package SY;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
public class TCPsever {
 
	public static void main(String[] args) {
		try {
			ServerSocket ss = new ServerSocket(1);// ����������
			Socket socket = ss.accept();// �ȴ�����ͨ��,Ӧ����ܵ�ַ������
			System.out.println("������"+socket);
			BufferedReader br=new BufferedReader(new InputStreamReader(socket.getInputStream()));
			BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
			while (true) {
				String str=null;
				if((str=br.readLine())!=null)
				{	if(str.equals("quit"))
					{
						System.out.println("��⵽�������!");
						break;
					}
					System.out.println(str);
					bw.write("�������ٸ��ͻ��˷�һ����Ϣ"+str);//���Զ��������л���
					bw.newLine();//�ֶ���ӻ���
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
