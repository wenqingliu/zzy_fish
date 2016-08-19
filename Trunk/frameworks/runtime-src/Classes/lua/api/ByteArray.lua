
--------------------------------
-- @module ByteArray
-- @extend Ref
-- @parent_module jt

--------------------------------
-- 
-- @function [parent=#ByteArray] writeShort 
-- @param self
-- @param #short value
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readBool 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeDouble 
-- @param self
-- @param #double value
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readByte 
-- @param self
-- @return char#char ret (return value: char)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeLONGLONG 
-- @param self
-- @param #long long value
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] getLength 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readFloat 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readTchar 
-- @param self
-- @param #int len
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeBool 
-- @param self
-- @param #bool value
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readInt 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readBYTE 
-- @param self
-- @return unsigned char#unsigned char ret (return value: unsigned char)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeFloat 
-- @param self
-- @param #float value
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeTchar 
-- @param self
-- @param #char value
-- @param #int len
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeUINT 
-- @param self
-- @param #unsigned int value
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readTCHAR 
-- @param self
-- @param #int len
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeDWORD 
-- @param self
-- @param #int value
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readShort 
-- @param self
-- @return short#short ret (return value: short)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeWORD 
-- @param self
-- @param #unsigned short value
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readDWORD 
-- @param self
-- @return unsigned long#unsigned long ret (return value: unsigned long)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeByte 
-- @param self
-- @param #char value
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readLONGLONG 
-- @param self
-- @return long long#long long ret (return value: long long)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readDouble 
-- @param self
-- @return double#double ret (return value: double)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] setPosition 
-- @param self
-- @param #int pos
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] getCPUEndian 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readUINT 
-- @param self
-- @return unsigned int#unsigned int ret (return value: unsigned int)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readString 
-- @param self
-- @param #int len
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] getPosition 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] getBytesAvailable 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeBYTE 
-- @param self
-- @param #unsigned char value
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeInt 
-- @param self
-- @param #int value
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] writeTCHAR 
-- @param self
-- @param #char value
-- @param #int len
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] readWORD 
-- @param self
-- @return unsigned short#unsigned short ret (return value: unsigned short)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] destroy 
-- @param self
-- @param #ByteArray ba
-- @return ByteArray#ByteArray self (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] create 
-- @param self
-- @param #int len
-- @return ByteArray#ByteArray ret (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] createWithPacket 
-- @param self
-- @param #TCP_BufferRef packet
-- @return ByteArray#ByteArray ret (return value: ByteArray)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] checkCPUEndian 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#ByteArray] createWithNotify 
-- @param self
-- @param #CNotify notify
-- @return ByteArray#ByteArray ret (return value: ByteArray)
        
return nil
