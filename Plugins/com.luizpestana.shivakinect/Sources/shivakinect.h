//-----------------------------------------------------------------------------
#ifndef __shivakinect_h__
#define __shivakinect_h__
//-----------------------------------------------------------------------------
#include "S3DXAIPackage.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Package declaration
//-----------------------------------------------------------------------------
class shivakinectPackage : public S3DX::AIPackage
{
public :

    //-------------------------------------------------------------------------
    //  Constructor / Destructor
	//-------------------------------------------------------------------------

	shivakinectPackage         ( ) ;
                               ~shivakinectPackage         ( ) ;

	//-------------------------------------------------------------------------
    //  Accessors
	//-------------------------------------------------------------------------

    const   char               *GetName             ( ) const ;
            S3DX::uint32        GetFunctionCount    ( ) const ;
            S3DX::uint32        GetConstantCount    ( ) const ;
    const   S3DX::AIFunction   *GetFunctionAt       ( S3DX::uint32 _iIndex ) const ;
    const   S3DX::AIConstant   *GetConstantAt       ( S3DX::uint32 _iIndex ) const ;

} ;

//-----------------------------------------------------------------------------
// Package API declaration
//-----------------------------------------------------------------------------
class shivakinectAPI
{
public :

    //-------------------------------------------------------------------------
    //  API Constructor
	//-------------------------------------------------------------------------
                                shivakinectAPI       ( ) 
                                {
                                    pfn_shivakinect_getSkeletonPosition               = NULL ;
                                    pfn_shivakinect_getFloorClipPlane                 = NULL ;
                                    pfn_shivakinect_getNormalToGravity                = NULL ;
									pfn_shivakinect_getSkeletonPosition               = NULL ;
                                    pfn_shivakinect_getSkeletonPositionHipCenter      = NULL ;
                                    pfn_shivakinect_getSkeletonPositionSpine          = NULL ;
                                    pfn_shivakinect_getSkeletonPositionShoulderCenter = NULL ;
                                    pfn_shivakinect_getSkeletonPositionHead           = NULL ;
                                    pfn_shivakinect_getSkeletonPositionShoulderLeft   = NULL ;
                                    pfn_shivakinect_getSkeletonPositionElbowLeft      = NULL ;
                                    pfn_shivakinect_getSkeletonPositionWristLeft      = NULL ;
                                    pfn_shivakinect_getSkeletonPositionHandLeft       = NULL ;
                                    pfn_shivakinect_getSkeletonPositionShoulderRight  = NULL ;
                                    pfn_shivakinect_getSkeletonPositionElbowRight     = NULL ;
                                    pfn_shivakinect_getSkeletonPositionWristRight     = NULL ;
                                    pfn_shivakinect_getSkeletonPositionHandRight      = NULL ;
                                    pfn_shivakinect_getSkeletonPositionHipLeft        = NULL ;
                                    pfn_shivakinect_getSkeletonPositionKneeLeft       = NULL ;
                                    pfn_shivakinect_getSkeletonPositionAnkleLeft      = NULL ;
                                    pfn_shivakinect_getSkeletonPositionFootLeft       = NULL ;
                                    pfn_shivakinect_getSkeletonPositionHipRight       = NULL ;
                                    pfn_shivakinect_getSkeletonPositionKneeRight      = NULL ;
                                    pfn_shivakinect_getSkeletonPositionAnkleRight     = NULL ;
                                    pfn_shivakinect_getSkeletonPositionFootRight      = NULL ;
                                    pfn_shivakinect_getSkeletonCenter = NULL ;
                                    pfn_shivakinect_getSkeletonCount = NULL ;
                                    pfn_shivakinect_unInit = NULL ;
                                    pfn_shivakinect_init  = NULL ;

                                }

	//-------------------------------------------------------------------------
	//  API Callbacks 
	//-------------------------------------------------------------------------

    S3DX::AICallback        pfn_shivakinect_getSkeletonPosition ;
    S3DX::AICallback        pfn_shivakinect_getFloorClipPlane ;
    S3DX::AICallback        pfn_shivakinect_getNormalToGravity ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionHipCenter ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionSpine ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionShoulderCenter ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionHead ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionShoulderLeft ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionElbowLeft ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionWristLeft ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionHandLeft ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionShoulderRight ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionElbowRight ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionWristRight ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionHandRight ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionHipLeft ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionKneeLeft ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionAnkleLeft ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionFootLeft ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionHipRight ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionKneeRight ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionAnkleRight ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonPositionFootRight ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonCenter ;
    S3DX::AICallback        pfn_shivakinect_getSkeletonCount ;
    S3DX::AICallback        pfn_shivakinect_unInit ;
    S3DX::AICallback        pfn_shivakinect_init ;

	//-------------------------------------------------------------------------
	//  API Functions 
	//-------------------------------------------------------------------------

    inline S3DX::AIVariables<3> getSkeletonPosition               ( const S3DX::AIVariable& nIndex, const S3DX::AIVariable& nPosition ) { S3DX_DECLARE_VIN_02( nIndex, nPosition ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPosition ) pfn_shivakinect_getSkeletonPosition ( 2, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getFloorClipPlane                 (  ) { S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getFloorClipPlane ) pfn_shivakinect_getFloorClipPlane ( 0, NULL, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getNormalToGravity                (  ) { S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getNormalToGravity ) pfn_shivakinect_getNormalToGravity ( 0, NULL, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionHipCenter      ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionHipCenter ) pfn_shivakinect_getSkeletonPositionHipCenter ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionSpine          ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionSpine ) pfn_shivakinect_getSkeletonPositionSpine ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionShoulderCenter ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionShoulderCenter ) pfn_shivakinect_getSkeletonPositionShoulderCenter ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionHead           ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionHead ) pfn_shivakinect_getSkeletonPositionHead ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionShoulderLeft   ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionShoulderLeft ) pfn_shivakinect_getSkeletonPositionShoulderLeft ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionElbowLeft      ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionElbowLeft ) pfn_shivakinect_getSkeletonPositionElbowLeft ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionWristLeft      ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionWristLeft ) pfn_shivakinect_getSkeletonPositionWristLeft ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionHandLeft       ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionHandLeft ) pfn_shivakinect_getSkeletonPositionHandLeft ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionShoulderRight  ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionShoulderRight ) pfn_shivakinect_getSkeletonPositionShoulderRight ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionElbowRight     ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionElbowRight ) pfn_shivakinect_getSkeletonPositionElbowRight ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionWristRight     ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionWristRight ) pfn_shivakinect_getSkeletonPositionWristRight ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionHandRight      ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionHandRight ) pfn_shivakinect_getSkeletonPositionHandRight ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionHipLeft        ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionHipLeft ) pfn_shivakinect_getSkeletonPositionHipLeft ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionKneeLeft       ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionKneeLeft ) pfn_shivakinect_getSkeletonPositionKneeLeft ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionAnkleLeft      ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionAnkleLeft ) pfn_shivakinect_getSkeletonPositionAnkleLeft ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionFootLeft       ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionFootLeft ) pfn_shivakinect_getSkeletonPositionFootLeft ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionHipRight       ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionHipRight ) pfn_shivakinect_getSkeletonPositionHipRight ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionKneeRight      ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionKneeRight ) pfn_shivakinect_getSkeletonPositionKneeRight ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionAnkleRight     ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionAnkleRight ) pfn_shivakinect_getSkeletonPositionAnkleRight ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonPositionFootRight      ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonPositionFootRight ) pfn_shivakinect_getSkeletonPositionFootRight ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariables<3> getSkeletonCenter ( const S3DX::AIVariable& nIndex ) { S3DX_DECLARE_VIN_01( nIndex ) ; S3DX::AIVariables<3> vOut ; if ( pfn_shivakinect_getSkeletonCenter ) pfn_shivakinect_getSkeletonCenter ( 1, vIn, vOut ); return vOut ; }
    inline S3DX::AIVariable     getSkeletonCount (  ) { S3DX::AIVariable vOut ; if ( pfn_shivakinect_getSkeletonCount ) pfn_shivakinect_getSkeletonCount ( 0, NULL, &vOut ); return vOut ; }
    inline void                 unInit (  ) { if ( pfn_shivakinect_unInit ) pfn_shivakinect_unInit ( 0, NULL, NULL );  }
    inline S3DX::AIVariable     init  (  ) { S3DX::AIVariable vOut ; if ( pfn_shivakinect_init ) pfn_shivakinect_init ( 0, NULL, &vOut ); return vOut ; }

 	//-------------------------------------------------------------------------
	//  API Constants 
	//-------------------------------------------------------------------------


} ;

extern shivakinectAPI shivakinect;

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
