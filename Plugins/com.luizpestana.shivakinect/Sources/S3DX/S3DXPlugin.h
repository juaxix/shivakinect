//-----------------------------------------------------------------------------
#ifndef __S3DXPlugin_h__
#define __S3DXPlugin_h__
//-----------------------------------------------------------------------------
#include "S3DXAIPackage.h"
#include "S3DXAIEngineAPI.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
namespace S3DX
//-----------------------------------------------------------------------------
{
    class Plugin
    {
    public :

        //---------------------------------------------------------------------
        //  Virtual destructor
        //
        virtual                        ~Plugin                      ( ) { }

        //---------------------------------------------------------------------
        //  SDK informations : this method is called by the engine at plugin 
        //  initialization time.
        //
        virtual         uint32          GetSDKVersion               ( ) const = 0 ;

        //---------------------------------------------------------------------
        //  Plugin contents directory : this method is called by the engine at
        //  plugin initialization time.
        //
        virtual         void            SetContentsDirectory        ( const char *_pDirectory ) = 0 ;

        //---------------------------------------------------------------------
        //  AI engine API : this method is called by the engine at plugin 
        //  initialization time.
        //
        virtual         AIEngineAPI    *GetAIEngineAPI              ( ) = 0 ;

        //---------------------------------------------------------------------
        //  AI packages : those method are called by the engine at plugin 
        //  initialization time.
        //
        virtual         uint32          GetAIPackageCount           ( ) const = 0 ;
        virtual const   AIPackage      *GetAIPackageAt              ( uint32 _iIndex ) const = 0 ;
    } ;

    //  Plugin entry point function typedef
    //
    typedef Plugin * ( * GetPluginProc ) ( ) ;

    //  Statically linked plugins functions
    //
    extern "C" uint32           GetStaticallyLinkedPluginCount  ( ) ;
    extern "C" Plugin          *GetStaticallyLinkedPluginAt     ( uint32  _iIndex  ) ;
    extern "C" const char      *GetStaticallyLinkedPluginNameAt ( uint32  _iIndex  ) ;
    extern "C" bool             RegisterStaticallyLinkedPlugin  ( Plugin *_pPlugin, const char *_pName ) ;
    extern "C" bool             RegisterDynamicallyLinkedPlugin ( Plugin *_pPlugin ) ;
}
//-----------------------------------------------------------------------------
// Macros
//
#ifdef S3DX_DLL
    #define S3DX_DECLARE_PLUGIN( _name_ )                                           \
        extern "C" S3DX_API S3DX::Plugin *GetPlugin ( ) ;                           \
        class _name_ : public S3DX::Plugin
#else
    #define S3DX_DECLARE_PLUGIN( _name_ )                                           \
        class S3DX_API _name_ : public S3DX::Plugin
#endif
//-----------------------------------------------------------------------------
#define S3DX_DECLARE_PLUGIN_INSTANCE( _name_ )                                      \
    private: static _name_ __oInstance ;                                            \
    public: static inline _name_ *GetInstance ( ) { return &__oInstance ; }         \
    public: S3DX::uint32 GetSDKVersion ( ) const;
//-----------------------------------------------------------------------------
#ifdef S3DX_DLL
    #define S3DX_IMPLEMENT_PLUGIN( _name_ )                                         \
        _name_ _name_::__oInstance ;                                                \
        S3DX::uint32 _name_::GetSDKVersion ( ) const { return S3DX_SDK_VERSION ; }  \
        S3DX::Plugin *GetPlugin ( ) { return _name_::GetInstance ( ) ; }
#else
    #define S3DX_IMPLEMENT_PLUGIN( _name_ )                                         \
        _name_ _name_::__oInstance ;                                                \
        S3DX::uint32 _name_::GetSDKVersion ( ) const { return S3DX_SDK_VERSION ; }  
#endif
//-----------------------------------------------------------------------------
#ifdef S3DX_DLL
    #define S3DX_REGISTER_PLUGIN( _name_ )
#else
    #define S3DX_REGISTER_PLUGIN( _name_ ) S3DX::RegisterStaticallyLinkedPlugin ( this, _name_ )
#endif
//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
