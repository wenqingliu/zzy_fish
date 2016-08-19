
--------------------------------
-- @module URLData
-- @extend Ref
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#URLData] setStatusCode 
-- @param self
-- @param #int statusCode
-- @return URLData#URLData self (return value: URLData)
        
--------------------------------
-- 
-- @function [parent=#URLData] getData 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#URLData] getStatusCode 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#URLData] setData 
-- @param self
-- @param #string data
-- @return URLData#URLData self (return value: URLData)
        
--------------------------------
-- @overload self, int, string         
-- @overload self         
-- @function [parent=#URLData] URLData
-- @param self
-- @param #int statusCode
-- @param #string data
-- @return URLData#URLData self (return value: URLData)

return nil
