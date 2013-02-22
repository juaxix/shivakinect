//-----------------------------------------------------------------------------
#ifndef __S3DXConfig_h__
#define __S3DXConfig_h__
//-----------------------------------------------------------------------------
#ifndef S3DX_SDK_VERSION
#define S3DX_SDK_VERSION    0x01090002  // 1.9.0.2
#endif
//-----------------------------------------------------------------------------
#if ( S3DX_SDK_VERSION >= 0x01090000 )
#   define S3DX_AVAILABLE_0x01090000( __exp__ ) __exp__
#else
#   define S3DX_AVAILABLE_0x01090000( ) 
#endif
#if ( S3DX_SDK_VERSION >= 0x01090001 )
#   define S3DX_AVAILABLE_0x01090001( __exp__ ) __exp__
#else
#   define S3DX_AVAILABLE_0x01090001( ) 
#endif
#if ( S3DX_SDK_VERSION >= 0x01090002 )
#   define S3DX_AVAILABLE_0x01090002( __exp__ ) __exp__
#else
#   define S3DX_AVAILABLE_0x01090002( ) 
#endif//-----------------------------------------------------------------------------
#define S3DX_AVAILABLE( __exp__, __sdk__ ) S3DX_AVAILABLE_##__sdk__( __exp__ )
//-----------------------------------------------------------------------------
#ifndef S3DX_MODULE_GUID
#define S3DX_MODULE_GUID    GUID_ShivaKinect
#endif
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
