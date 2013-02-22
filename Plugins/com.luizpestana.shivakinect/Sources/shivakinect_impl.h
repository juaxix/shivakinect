//-----------------------------------------------------------------------------
#ifndef __shivakinect_impl_h__
#define __shivakinect_impl_h__
//-----------------------------------------------------------------------------

class PluginShivaKinect
{
public:
	bool Init();
	void UnInit();

	Vector4 FloorClipPlane;
	Vector4 NormalToGravity;

    int SkeletonCount;
	Vector4 SkeletonCenter[NUI_SKELETON_COUNT];
	Vector4 SkeletonPosition[NUI_SKELETON_COUNT][NUI_SKELETON_POSITION_COUNT];

private:
    static DWORD WINAPI ProcessThread(LPVOID pParam);

    HANDLE m_hThNuiProcess;
    HANDLE m_hEvNuiProcessStop;
	HANDLE m_hNextSkeletonEvent;
};

#endif
