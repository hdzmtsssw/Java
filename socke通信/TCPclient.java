package SYY;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
public class TCPclient {
 
	public static void main(String[] args) {
		try {
			Socket socket=new Socket(InetAddress.getLocalHost(),1);
			System.out.println("客户端"+socket);
			 
			//从客户端向服务端输出
			OutputStream os = socket.getOutputStream();
			os.write("客户端的消息终于发出去啦\n".getBytes());
			os.write("开心开心好开心\n".getBytes());
			os.write("quit".getBytes());
			System.out.println("客户端：send！");
			socket.shutdownOutput();
			
			BufferedReader br=new BufferedReader(new InputStreamReader(socket.getInputStream()));
			String str;
			while((str=br.readLine())!=null)
			{
				System.out.println(str);
			}
			br.close();
			socket.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
