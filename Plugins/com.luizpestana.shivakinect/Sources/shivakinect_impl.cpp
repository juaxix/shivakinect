//-----------------------------------------------------------------------------
#include "PrecompiledHeader.h"
#include "shivakinect_impl.h"
#include <mmsystem.h>
//-----------------------------------------------------------------------------

bool PluginShivaKinect::Init()
{
	HRESULT hr;

	m_hNextSkeletonEvent = CreateEvent( NULL, TRUE, FALSE, NULL );

	hr = NuiInitialize( NUI_INITIALIZE_FLAG_USES_DEPTH_AND_PLAYER_INDEX | NUI_INITIALIZE_FLAG_USES_SKELETON | NUI_INITIALIZE_FLAG_USES_COLOR);
	if( FAILED( hr ) ) return false;

	hr = NuiSkeletonTrackingEnable( m_hNextSkeletonEvent, 0 );
	if( FAILED( hr ) ) return false;

    m_hEvNuiProcessStop = CreateEvent(NULL,FALSE,FALSE,NULL);
    m_hThNuiProcess = CreateThread(NULL,0,ProcessThread,this,0,NULL);

	return true;
}

void PluginShivaKinect::UnInit()
{
    if(m_hEvNuiProcessStop!=NULL)
    {
        SetEvent(m_hEvNuiProcessStop);

        if(m_hThNuiProcess!=NULL)
        {
            WaitForSingleObject(m_hThNuiProcess,INFINITE);
            CloseHandle(m_hThNuiProcess);
			m_hThNuiProcess = NULL;
        }
        CloseHandle(m_hEvNuiProcessStop);
		m_hEvNuiProcessStop = NULL;
    }

    NuiShutdown( );
    if( m_hNextSkeletonEvent && ( m_hNextSkeletonEvent != INVALID_HANDLE_VALUE ) )
    {
        CloseHandle( m_hNextSkeletonEvent );
        m_hNextSkeletonEvent = NULL;
    }
}

DWORD WINAPI PluginShivaKinect::ProcessThread(LPVOID pParam)
{
    PluginShivaKinect *pthis = (PluginShivaKinect *) pParam;
    HANDLE hEvents[2];
    int nEventIdx,t,dt;

    hEvents[0] = pthis->m_hEvNuiProcessStop;
    hEvents[1] = pthis->m_hNextSkeletonEvent;

    while(1)
    {
        nEventIdx = WaitForMultipleObjects(sizeof(hEvents)/sizeof(hEvents[0]),hEvents,FALSE,100);

        if(nEventIdx==0)
            break;            
		
		NUI_SKELETON_FRAME SkeletonFrame;

		HRESULT hr = NuiSkeletonGetNextFrame( 0, &SkeletonFrame );
		NuiTransformSmooth(&SkeletonFrame,NULL);

		pthis->FloorClipPlane = SkeletonFrame.vFloorClipPlane;
		pthis->NormalToGravity = SkeletonFrame.vNormalToGravity;

		pthis->SkeletonCount = 0;
		for( int i = 0 ; i < NUI_SKELETON_COUNT ; i++ )
		{
			if( SkeletonFrame.SkeletonData[i].eTrackingState == NUI_SKELETON_TRACKED )
			{
				if (pthis->SkeletonCount >= 2) break;

				pthis->SkeletonCenter[pthis->SkeletonCount] = SkeletonFrame.SkeletonData[i].Position;

				for ( int j = 0; j < NUI_SKELETON_POSITION_COUNT; j++)
					pthis->SkeletonPosition[pthis->SkeletonCount][j] = SkeletonFrame.SkeletonData[i].SkeletonPositions[j];

				pthis->SkeletonCount++;
			}
		}
    }

    return (0);
}