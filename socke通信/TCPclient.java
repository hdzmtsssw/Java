package SYY;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
public class TCPclient {
 
	public static void main(String[] args) {
		try {
			Socket socket=new Socket(InetAddress.getLocalHost(),1);
			System.out.println("�ͻ���"+socket);
			 
			//�ӿͻ������������
			OutputStream os = socket.getOutputStream();
			os.write("�ͻ��˵���Ϣ���ڷ���ȥ��\n".getBytes());
			os.write("���Ŀ��ĺÿ���\n".getBytes());
			os.write("quit".getBytes());
			System.out.println("�ͻ��ˣ�send��");
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
