//-----------------------------------------------------------------------------
#include "PrecompiledHeader.h"
#include "shivakinect.h"
#include "shivakinect_impl.h"
//-----------------------------------------------------------------------------

#ifdef S3DX_DLL
	shivakinectAPI shivakinect ;
#endif

// Plugin Code
PluginShivaKinect pShivaKinect;

//-----------------------------------------------------------------------------
//  Callbacks
//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPosition ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPosition" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex    = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;
    S3DX::AIVariable nPosition = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT) && (nPosition >= 0) && (nPosition < NUI_SKELETON_POSITION_COUNT))
	{
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}
	
    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getFloorClipPlane ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getFloorClipPlane" ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;
	S3DX::AIVariable d = 0;

	// Plugin Code
	x = pShivaKinect.FloorClipPlane.x;
	y = pShivaKinect.FloorClipPlane.y;
	z = pShivaKinect.FloorClipPlane.z;
	d = pShivaKinect.FloorClipPlane.w;

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;
	_pOut[iReturnCount++] = d ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getNormalToGravity ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getNormalToGravity" ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	x = pShivaKinect.NormalToGravity.x;
	y = pShivaKinect.NormalToGravity.y;
	z = pShivaKinect.NormalToGravity.z;

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionHipCenter ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionHipCenter" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_HIP_CENTER;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionSpine ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionSpine" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_SPINE;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}
	
    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionShoulderCenter ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionShoulderCenter" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_SHOULDER_CENTER;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}
	
    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionHead ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionHead" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_HEAD;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionShoulderLeft ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionShoulderLeft" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_SHOULDER_LEFT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionElbowLeft ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionElbowLeft" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_ELBOW_LEFT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionWristLeft ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionWristLeft" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_WRIST_LEFT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionHandLeft ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionHandLeft" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_HAND_LEFT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionShoulderRight ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionShoulderRight" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_SHOULDER_RIGHT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionElbowRight ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionElbowRight" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_ELBOW_RIGHT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionWristRight ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionWristRight" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_WRIST_RIGHT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionHandRight ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionHandRight" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_HAND_RIGHT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionHipLeft ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionHipLeft" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_HIP_LEFT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionKneeLeft ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionKneeLeft" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_KNEE_LEFT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionAnkleLeft ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionAnkleLeft" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_ANKLE_LEFT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionFootLeft ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionFootLeft" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_FOOT_LEFT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionHipRight ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionHipRight" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_HIP_RIGHT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionKneeRight ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionKneeRight" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_KNEE_RIGHT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionAnkleRight ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionAnkleRight" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_ANKLE_RIGHT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonPositionFootRight ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonPositionFootRight" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		int nPosition = NUI_SKELETON_POSITION_FOOT_RIGHT;
		x = pShivaKinect.SkeletonPosition[nIndex][nPosition].x;
		y = pShivaKinect.SkeletonPosition[nIndex][nPosition].y;
		z = pShivaKinect.SkeletonPosition[nIndex][nPosition].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonCenter ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonCenter" ) ;

    // Input Parameters 
    int iInputCount = 0 ;
    S3DX::AIVariable nIndex = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable x = 0;
    S3DX::AIVariable y = 0;
    S3DX::AIVariable z = 0;

	// Plugin Code
	if ((nIndex >= 0) && (nIndex < NUI_SKELETON_COUNT))
	{
		x = pShivaKinect.SkeletonCenter[nIndex].x;
		y = pShivaKinect.SkeletonCenter[nIndex].y;
		z = pShivaKinect.SkeletonCenter[nIndex].z;
	}

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = x ;
    _pOut[iReturnCount++] = y ;
    _pOut[iReturnCount++] = z ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_getSkeletonCount ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.getSkeletonCount" ) ;

    // Output Parameters 
    S3DX::AIVariable nCount ;

	// Plugin Code
	nCount = pShivaKinect.SkeletonCount;

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = nCount ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_unInit ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.unInit" ) ;

	// Plugin Code
	pShivaKinect.UnInit();

    S3DX_API_PROFILING_STOP( ) ;
    return 0;
}

//-----------------------------------------------------------------------------

int Callback_shivakinect_init ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "shivakinect.init" ) ;

    // Output Parameters 
    S3DX::AIVariable bOK ;

	// Plugin Code
	bOK = pShivaKinect.Init();

    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = bOK ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------
//  Constructor / Destructor
//-----------------------------------------------------------------------------

shivakinectPackage::shivakinectPackage ( )
{
#ifdef S3DX_DLL
    shivakinect.pfn_shivakinect_getSkeletonPosition               = Callback_shivakinect_getSkeletonPosition               ;
    shivakinect.pfn_shivakinect_getFloorClipPlane                 = Callback_shivakinect_getFloorClipPlane                 ;
    shivakinect.pfn_shivakinect_getNormalToGravity                = Callback_shivakinect_getNormalToGravity                ;
    shivakinect.pfn_shivakinect_getSkeletonPositionHipCenter      = Callback_shivakinect_getSkeletonPositionHipCenter      ;
    shivakinect.pfn_shivakinect_getSkeletonPositionSpine          = Callback_shivakinect_getSkeletonPositionSpine          ;
    shivakinect.pfn_shivakinect_getSkeletonPositionShoulderCenter = Callback_shivakinect_getSkeletonPositionShoulderCenter ;
    shivakinect.pfn_shivakinect_getSkeletonPositionHead           = Callback_shivakinect_getSkeletonPositionHead           ;
    shivakinect.pfn_shivakinect_getSkeletonPositionShoulderLeft   = Callback_shivakinect_getSkeletonPositionShoulderLeft   ;
    shivakinect.pfn_shivakinect_getSkeletonPositionElbowLeft      = Callback_shivakinect_getSkeletonPositionElbowLeft      ;
    shivakinect.pfn_shivakinect_getSkeletonPositionWristLeft      = Callback_shivakinect_getSkeletonPositionWristLeft      ;
    shivakinect.pfn_shivakinect_getSkeletonPositionHandLeft       = Callback_shivakinect_getSkeletonPositionHandLeft       ;
    shivakinect.pfn_shivakinect_getSkeletonPositionShoulderRight  = Callback_shivakinect_getSkeletonPositionShoulderRight  ;
    shivakinect.pfn_shivakinect_getSkeletonPositionElbowRight     = Callback_shivakinect_getSkeletonPositionElbowRight     ;
    shivakinect.pfn_shivakinect_getSkeletonPositionWristRight     = Callback_shivakinect_getSkeletonPositionWristRight     ;
    shivakinect.pfn_shivakinect_getSkeletonPositionHandRight      = Callback_shivakinect_getSkeletonPositionHandRight      ;
    shivakinect.pfn_shivakinect_getSkeletonPositionHipLeft        = Callback_shivakinect_getSkeletonPositionHipLeft        ;
    shivakinect.pfn_shivakinect_getSkeletonPositionKneeLeft       = Callback_shivakinect_getSkeletonPositionKneeLeft       ;
    shivakinect.pfn_shivakinect_getSkeletonPositionAnkleLeft      = Callback_shivakinect_getSkeletonPositionAnkleLeft      ;
    shivakinect.pfn_shivakinect_getSkeletonPositionFootLeft       = Callback_shivakinect_getSkeletonPositionFootLeft       ;
    shivakinect.pfn_shivakinect_getSkeletonPositionHipRight       = Callback_shivakinect_getSkeletonPositionHipRight       ;
    shivakinect.pfn_shivakinect_getSkeletonPositionKneeRight      = Callback_shivakinect_getSkeletonPositionKneeRight      ;
    shivakinect.pfn_shivakinect_getSkeletonPositionAnkleRight     = Callback_shivakinect_getSkeletonPositionAnkleRight     ;
    shivakinect.pfn_shivakinect_getSkeletonPositionFootRight      = Callback_shivakinect_getSkeletonPositionFootRight      ;
    shivakinect.pfn_shivakinect_getSkeletonCenter = Callback_shivakinect_getSkeletonCenter ;
    shivakinect.pfn_shivakinect_getSkeletonCount = Callback_shivakinect_getSkeletonCount ;
    shivakinect.pfn_shivakinect_unInit = Callback_shivakinect_unInit ;
    shivakinect.pfn_shivakinect_init  = Callback_shivakinect_init  ;
	
#endif
}

//-----------------------------------------------------------------------------

shivakinectPackage::~shivakinectPackage ( )
{
}

//-----------------------------------------------------------------------------
//  Functions table
//-----------------------------------------------------------------------------

static S3DX::AIFunction aMyFunctions [ ] =
{
    { "getSkeletonPosition"              , Callback_shivakinect_getSkeletonPosition              , "x, y, z"   , "nIndex, nPosition", "Get position of skeleton node."      , 0 }, 
    { "getFloorClipPlane"                , Callback_shivakinect_getFloorClipPlane                , "x, y, z, d", ""      , "Get plane coordinates of floor."     , 0 }, 
    { "getNormalToGravity"               , Callback_shivakinect_getNormalToGravity               , "x, y, z", ""      , "Get normal vector of gravity."       , 0 }, 
	{ "getSkeletonPositionHipCenter"     , Callback_shivakinect_getSkeletonPositionHipCenter     , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionSpine"         , Callback_shivakinect_getSkeletonPositionSpine         , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionShoulderCenter", Callback_shivakinect_getSkeletonPositionShoulderCenter, "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionHead"          , Callback_shivakinect_getSkeletonPositionHead          , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionShoulderLeft"  , Callback_shivakinect_getSkeletonPositionShoulderLeft  , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionElbowLeft"     , Callback_shivakinect_getSkeletonPositionElbowLeft     , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionWristLeft"     , Callback_shivakinect_getSkeletonPositionWristLeft     , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionHandLeft"      , Callback_shivakinect_getSkeletonPositionHandLeft      , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionShoulderRight" , Callback_shivakinect_getSkeletonPositionShoulderRight , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionElbowRight"    , Callback_shivakinect_getSkeletonPositionElbowRight    , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionWristRight"    , Callback_shivakinect_getSkeletonPositionWristRight    , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionHandRight"     , Callback_shivakinect_getSkeletonPositionHandRight     , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionHipLeft"       , Callback_shivakinect_getSkeletonPositionHipLeft       , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionKneeLeft"      , Callback_shivakinect_getSkeletonPositionKneeLeft      , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionAnkleLeft"     , Callback_shivakinect_getSkeletonPositionAnkleLeft     , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionFootLeft"      , Callback_shivakinect_getSkeletonPositionFootLeft      , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionHipRight"      , Callback_shivakinect_getSkeletonPositionHipRight      , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionKneeRight"     , Callback_shivakinect_getSkeletonPositionKneeRight     , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionAnkleRight"    , Callback_shivakinect_getSkeletonPositionAnkleRight    , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonPositionFootRight"     , Callback_shivakinect_getSkeletonPositionFootRight     , "x, y, z", "nIndex", "Get position of skeleton node."      , 0 }, 
    { "getSkeletonCenter", Callback_shivakinect_getSkeletonCenter, "x, y, z", "nIndex", "Get position of skeleton center."    , 0 }, 
    { "getSkeletonCount", Callback_shivakinect_getSkeletonCount, "nCount", "", "Return a number of active skeletons.", 0 }, 
    { "unInit", Callback_shivakinect_unInit, ""   , "", "Disactivate Kinect device.", 0 }, 
    { "init" , Callback_shivakinect_init , "bOK"     , ""          , "Activate Kinect device.", 0 }, 
    //{ NULL, NULL, NULL, NULL, NULL, 0}
} ;

//-----------------------------------------------------------------------------
//  Constants table
//-----------------------------------------------------------------------------

static S3DX::AIConstant aMyConstants [ ] =
{
	{ NULL, 0, NULL, 0}
} ;

//-----------------------------------------------------------------------------
//  Accessors
//-----------------------------------------------------------------------------

const char *shivakinectPackage::GetName ( ) const
{
    return "shivakinect" ;
}

//-----------------------------------------------------------------------------

S3DX::uint32 shivakinectPackage::GetFunctionCount ( ) const
{
	if ( aMyFunctions[0].pName == NULL )
	{
		return 0 ;
	}
	else
	{
		return sizeof( aMyFunctions ) / sizeof( S3DX::AIFunction ) ;
	}
}

//-----------------------------------------------------------------------------

S3DX::uint32 shivakinectPackage::GetConstantCount ( ) const
{
	if ( aMyConstants[0].pName == NULL )
	{
		return 0 ;
	}
	else
	{
		return sizeof( aMyConstants ) / sizeof( S3DX::AIConstant ) ;
	}
}

//-----------------------------------------------------------------------------

const S3DX::AIFunction *shivakinectPackage::GetFunctionAt ( S3DX::uint32 _iIndex ) const
{
    return &aMyFunctions[ _iIndex ] ;
}

//-----------------------------------------------------------------------------

const S3DX::AIConstant *shivakinectPackage::GetConstantAt ( S3DX::uint32 _iIndex ) const
{
    return &aMyConstants[ _iIndex ] ;
}
