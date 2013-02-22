--------------------------------------------------------------------------------
--  Handler.......... : onInit
--  Author........... : 
--  Description...... : 
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
function ShivaKinectDemo.onInit (  )
--------------------------------------------------------------------------------
	
    application.setCurrentUserScene ( "ShivaKinectDemo" )

    this.hDotModel1 ( scene.createRuntimeObject ( application.getCurrentUserScene ( ), "CenterModel" ) )
    for i = 1, 20 do
        local hModelPt = scene.createRuntimeObject ( application.getCurrentUserScene ( ), "DotModel" )
        object.setParent ( hModelPt, this.hDotModel1 ( ), false )
        hashtable.add ( this.hDotModelPoints ( ), "1_".. i, hModelPt )
    end
    object.setVisible ( this.hDotModel1 ( ), false )
    
    this.hDotModel2 ( scene.createRuntimeObject ( application.getCurrentUserScene ( ), "CenterModel" ) )
    for i = 1, 20 do
        local hModelPt = scene.createRuntimeObject ( application.getCurrentUserScene ( ), "DotModel" )
        object.setParent ( hModelPt, this.hDotModel2 ( ), false )
        hashtable.add ( this.hDotModelPoints ( ), "2_".. i, hModelPt )
    end
    object.setVisible ( this.hDotModel2 ( ), false )
    
    if ( shivakinect.init ( ) ) then
    
        log.message ( "Kinect Ok!" )
    
    else
    
        log.message ( "Kinect Error!" )
    
    end
    
--------------------------------------------------------------------------------
end
--------------------------------------------------------------------------------
