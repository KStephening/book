# java中的网络支持

## 类

- InetAddress---表示网络上的硬件资源
- URL--统一资源定位符,通过URL可以读取或写入网络数据
- Sockets--使用TCP协议实现网络通信的Socket相关类
- Datagram--使用UDP协议,将数据保存在数据报中,通过网络通信

### InetAddress

```java
@Test
   public void testAddress() throws UnknownHostException {
      //获取本机
      InetAddress address = InetAddress.getLocalHost();
      System.out.println("本机的计算机名:"+address.getHostName());
      System.out.println("本机的计算机地址:"+address.getHostAddress());
      System.out.println("本机的计算机字节数组的ip:"+ Arrays.toString(address.getAddress()));
      System.out.println("Address:"+address);

      //根据计算机名获取
      InetAddress address1 = InetAddress.getByName("sunbiaolong");
      System.out.println("address1:"+address1);
//      通过字节数组
      InetAddress address2 = InetAddress.getByAddress(new byte[]{-64, -88, 17, 2});
      System.out.println("address2:"+address2);

      //根据计算机名获取
      InetAddress address3 = InetAddress.getByName("192.168.17.2");
      System.out.println("address3:"+address3);
   }
```

### URL

- 协议名称
- 冒号
- 资源

```java
/**
    * URL的基本方法
    */
   @Test
   public void testURL() {
      try {
         URL imooc = new URL("https://www.imooc.com/");
         //?后面跟的是参数,#后面跟的是锚点
         URL url1 = new URL(imooc, "/index.html?username=tom#test");
         //https
         System.out.println("协议:" + url1.getProtocol());
//       www.imooc.com
         System.out.println("主机:" + url1.getHost());
         //如果未指定端口号,则使用默认的端口号
         //此时的getPorty方法返回值为-1
         System.out.println("端口:" + url1.getPort());
         //    /index.html
         System.out.println("文件路径:" + url1.getPath());
         //   /index.html?username=tom
         System.out.println("文件名:" + url1.getFile());
         //test
         System.out.println("相对路径:" + url1.getRef());
         //username=tom
         System.out.println("查询字符串:" + url1.getQuery());
      } catch (MalformedURLException e) {
         e.printStackTrace();
      }
   }

   /**
    * 通过URL读取资源
    */
   @Test
   public void testGetResource() throws IOException {
      URL url = new URL("http://www.baidu.com");
      //获取输入流
      InputStream inputStream = url.openStream();
      //字节流转为字符流
      InputStreamReader inputStreamReader = new InputStreamReader(inputStream, "utf-8");
      //添加缓冲
      BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
      //读取数据
      String dataLine = bufferedReader.readLine();
      //循环读取
      while (dataLine!=null){
         System.out.println(dataLine);
         dataLine = bufferedReader.readLine();
      }
      bufferedReader.close();
      inputStreamReader.close();
      inputStream.close();
   }
```

>  `InputStreamReader inputStreamReader = new InputStreamReader(inputStream, "utf-8");`--注意设置字符编码,否则容易出错

