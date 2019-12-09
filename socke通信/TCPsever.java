package SY;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
public class TCPsever {
 
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(1);// 创建服务器
			Socket socket = ss.accept();// 等待建立通道,应答接受地址和内容
			System.out.println("服务器"+socket);
			BufferedReader br=new BufferedReader(new InputStreamReader(socket.getInputStream()));
			BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
			while (true) {
				String str=null;
				if((str=br.readLine())!=null)
				{	if(str.equals("quit"))
					{
						System.out.println("检测到输入结束!");
						break;
					}
					System.out.println(str);
					bw.write("服务器再给客户端发一个消息"+str);//会自动丢掉所有换行
					bw.newLine();//手动添加换行
					bw.flush();
				}
			}
			br.close();
			socket.close();
			ss.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
