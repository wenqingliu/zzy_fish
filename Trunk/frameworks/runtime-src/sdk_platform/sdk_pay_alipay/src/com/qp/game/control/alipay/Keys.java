/*
 * Copyright (C) 2010 The MobileSecurePay Project
 * All right reserved.
 * author: shiqun.shi@alipay.com
 */

package com.qp.game.control.alipay;

//
// 请参考 Android平台安全支付服务(msp)应用开发接口(4.2 RSA算法签名)部分，并使用压缩包中的openssl RSA密钥生成工具，生成一套RSA公私钥。
// 这里签名时，只需要使用生成的RSA私钥。
// Note: 为安全起见，使用RSA私钥进行签名的操作过程，应该尽量放到商家服务器端去进行。
public final class Keys {

    // 合作商户ID，用签约支付宝账号登录www.alipay.com后，在商家服务页面中获取。
	public static final String DEFAULT_PARTNER = "2088011663161722";

    // 商户收款的支付宝账号
	public static final String DEFAULT_SELLER = "65682073@qq.com";

    // 商户（RSA）私钥
//	public static final String PRIVATE = "MIICXQIBAAKBgQCdE0u4F6kmZllNlHH6yBUJ5t3d+U07K1rdZiyKZmyYVjMao5+b" +
//		"VNBQvq2tKwZ8GUlGoZMJNWIA64ODd3xtCpnByf8jIak+OTbvbf9CRDRMumRNUzlG" +
//		"OmT+fPZpJbFuQ8PTv7FT5aj6U14LdAcvg7+VbEA3U2w4aiG/oKmPrUzgvwIDAQAB" +
//		"AoGBAIcGfFO/OzAAUYpILobnEnbVmCnl0gcoKM8jsuwySe3WQ84FlAGCMiUHFONE" +
//		"lil9zyjBYlVLJ3kk+4O65iISN8Mu7Dw4QGN19rI9mpV8+1OiRE7J7a0bA5FRiH1S" +
//		"WCIsBwsgQb+2i6O1pJ/qVQUizm3n9BJTSyWUNBP+OSmRfSDpAkEAylJn05FznJ/a" +
//		"90LM3ZibNeCWSNysGvEBUdymLflLu2AjFnUo9Jn9y1Uz2w6DOVwSUIXjh0iiaol/" +
//		"h2DdxpMIdQJBAMa/xU3q4Qj+Os0GSTBZHqxDCe/mQFHOu5Zzb2hCsNNQ2YB+TERA" +
//		"AJeuzscVxELrk7FGEfvaseNum4Y7cNc2veMCQBWYNBLF3JQkD8gCbkFcr3xRq1i9" +
//		"jPUXMi/doDMZ/7ZRLY2RFbz9zrPsNSu1YdY2eJH1qHJhE0zRvjXh5eny+Z0CQQCN" +
//		"ExyDBUD8+DBWzapv1iKOlftcvOxU5VCEJ6YhtIz9QjtRGNUb8O46vMtrx0iLU9p/" +
//		"D8S+J+rzC9T7QAAF04aPAkANoZedvI3P2RNuaMHtzGP6NWGYnr7aHk6hZw1F+2lD" +
//		"CC5E39NTCPMaem0np4jvU7E7qA7gnOeDlrVMDFv3EeJy";

    // 商户（RSA）私钥
	public static final String PRIVATE = "MIICdgIBADANBgkqhkiG9w0BAQEFAASCAmAwggJcAgEAAoGBAMaTB8PqxPQcSRkVGvIyJUTCsRPu0g1jg8rutA1gycEDPFzO2eP8uu/6i+fbcA9C4YHbq4kLoAmxiRkww22dpi49f5mkrPzQgd2oCejVv3lJdeMkEQeMjfttpTzpeHsLvRV/50RdCI7cdd7FbUrzEWhSrackI+XKzdcqwrN0GnYZAgMBAAECgYBNPujoZ61SIKa24SToTmV9CBeGX4LKvomIKa9U/O++65lRqQ3NyISX0ekWuqAu7591upRR7XnGC4//gp6jR45bAguprrKoRwTXfNjnK0sthZ1B1EvKrddrwuVFkeRg685WZsMGGeyrYyP9YB6wHjVqq07SY56EigpKByJYUsUGeQJBAPuknwe7eupx+oIXf6BYFL1tqvtXtYxc+xmGWBa4/rdPW/xci8yFzPvu85UPkeVN8RkIAiLqjDdwuFs+sDuk+acCQQDKAzAr1OYyfMDE3Gt0uPuBDxLEyz6qEuaPCMcRgiS+y+R7EpMo/pOwDXNaBJdnzQ6BG6f+JGbOCdW2tZAsS4o/AkAn3SZMRUjthuzWWv6e2hU/BPaHJpfeCoTEwGGIB/ph87JwwgBrf+6/IlV4EaVdHAHLo1cjTOC1j6fE3KNyb2oVAkEAk0ANrfWLMoQDE7xDy5pHIcT1/mLUM66BRwOz74w48qa2zgs1H62pw6uaSKSOJIixKOUa6EJqeYdrs7nW9KK/iwJAOAJcJuEfXcrE7BS9IufQsqTo4A0JH6v0z9wZ1yDMi2d3laVHII+PJtif8wwDW8EWgQRTRu/USTNFsYlGGlE87A==";

    // 支付宝（RSA）公钥
	public static final String PUBLIC = "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCnxj/9qwVfgoUh/y2W89L6BkRAFljhNhgPdyPuBV64bfQNN1PjbCzkIM6qRdKBoLPXmKKMiFYnkd6rAoprih3/PrQEB/VsW8OoM8fxn67UDYuyBTqA23MML9q1+ilIZwBC2AQ2UBVOrFXfFl75p6/B5KsiNG9zpgmLCUYuLkxpLQIDAQAB";

}
