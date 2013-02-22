--------------------------------------------------------------------------------
--  Handler.......... : onEnterFrame
--  Author........... : 
--  Description...... : 
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
function ShivaKinectDemo.onEnterFrame (  )
--------------------------------------------------------------------------------
	   
    local nCount = shivakinect.getSkeletonCount ( )
    if (nCount > 0) then
       
        if (not object.isVisible ( this.hDotModel1 ( ) ) ) then
            object.setVisible ( this.hDotModel1 ( ), true )
        end
        
        local x, y, z = shivakinect.getSkeletonCenter ( 0 )
        object.setTranslation ( this.hDotModel1 ( ), x, y, z, object.kGlobalSpace )
        
        local hCamera = application.getCurrentUserActiveCamera ( )
        object.setTranslation ( hCamera, x, y + 2, z + 3, object.kGlobalSpace )
        object.lookAt ( hCamera, x, y, z, object.kGlobalSpace, 1 )
        
        for i = 1, 20 do
            local x, y, z = shivakinect.getSkeletonPosition ( 0, i - 1 )
            object.setTranslation ( hashtable.get ( this.hDotModelPoints ( ), "1_".. i ), x, y, z, object.kGlobalSpace )
        end
                  
        if (nCount > 1) then

            if (not object.isVisible ( this.hDotModel2 ( ) ) ) then
                object.setVisible ( this.hDotModel2 ( ), true )
            end
                
            local x, y, z = shivakinect.getSkeletonCenter ( 1 )
            object.setTranslation ( this.hDotModel2 ( ), x, y, z, object.kGlobalSpace )
            for i = 1, 20 do
                local x, y, z = shivakinect.getSkeletonPosition ( 1, i - 1 )
                object.setTranslation ( hashtable.get ( this.hDotModelPoints ( ), "2_".. i ), x, y, z, object.kGlobalSpace )
            end
        
        else
        
            if (object.isVisible ( this.hDotModel2 ( ) ) ) then
                object.setVisible ( this.hDotModel2 ( ), false )
            end
        
        end
    
    else
    
        if (object.isVisible ( this.hDotModel1 ( ) ) ) then
            object.setVisible ( this.hDotModel1 ( ), false )
            object.setVisible ( this.hDotModel2 ( ), false )
        end
    
    end
	
--------------------------------------------------------------------------------
end
--------------------------------------------------------------------------------
