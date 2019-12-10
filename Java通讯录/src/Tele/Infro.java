package Tele;

import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.SynchronousQueue;
import javax.swing.*;

class Infro{
    public String id;
    public String name;
    public String sex;
    public String address;
    public String e_mail;
    public String phoneNumber;
    static int index = 0;
    static ArrayList<Infro> list = new ArrayList();
    static int len = list.size();
    //���캯��
    public Infro(String id,String name,String sex,String address,String e_mail,String phoneNumber){
        this.id = id;
        this.name = name;
        this.sex = sex;
        this.address = address;
        this.e_mail = e_mail;
        this.phoneNumber = phoneNumber;
    }
    public String toString(){
        return "��ţ�"+id+" ������"+name+" �Ա�"+sex+" ͨѶ��ַ��"+address+" �����ַ��"+e_mail+" �绰��"+phoneNumber;
    }

    /*    * ��ӹ���*   */
    public static void addFunction(){//��ӹ���
        Infro infro = new Infro("","","","","","");
        System.out.println("��������ӵ����ݣ�");
        Scanner in = new Scanner(System.in);
        System.out.println("�����ţ�");
        infro.id = in.next();
        System.out.println("����������");
        infro.name = in.next();
        System.out.println("�����Ա�");
        infro.sex = in.next();
        System.out.println("����ͨѶ��ַ��");
        infro.address = in.next();
        System.out.println("���������ַ��");
        infro.e_mail = in.next();
        System.out.println("����绰��");
        infro.phoneNumber = in.next();
        list.add(index,infro);
        index++;
        if(list.isEmpty()){
            System.out.println("�������ʧ��");
        }else{
            System.out.println("������ӳɹ�");
            len++;//list���ϳ��ȼ�һ
//          System.out.println(list.get(0).toString());
        }

    }


    /*    * ɾ������*   */
     public static void deleteFunction(){
         System.out.println("����Ҫɾ������ϵ�˵ı��");
         Scanner in_2 = new Scanner(System.in);
         String d1 = in_2.nextLine();
         java.util.Iterator<Infro> it = list.iterator();
         while (it.hasNext()){
               Infro infro = it.next();
               if (infro.id.equals(d1)){
                    it.remove();
                    --index;//һ��Ҫ���������������ɾ������������Ӳ�����ʱ�������쳣��������ָ�룬ջ��
                    System.out.println("ɾ�����"+"��ʱͨѶ¼��¼����Ϊ��" + --len);
               }
            }
        }


     /*    * �޸Ĺ���*   */
     public static void reditFunction(){
         System.out.println("����Ҫ�޸ĵ�ͨѶ¼��Id");
         Scanner in_r = new Scanner(System.in);
         String r1 = in_r.nextLine();
         for(int a = 0; a < len;a++){
             if(r1.equals(list.get(a).id)){
                 System.out.println("�����޸ĺ��������");
                 String name_1 = in_r.next();
                 list.get(a).name = name_1;
                 System.out.println("�����޸ĺ���Ա�");
                 String sex_1 = in_r.next();
                 list.get(a).sex = sex_1;
                 System.out.println("�����޸ĺ��ͨѶ��ַ��");
                 String address_1 = in_r.next();
                 list.get(a).address = address_1;
                 System.out.println("�����޸ĺ�������ַ��");
                 String e_mail_1 = in_r.next();
                 list.get(a).e_mail = e_mail_1;
                 System.out.println("�����޸ĺ�ĵ绰��");
                 String phoneNumber_1 = in_r.next();
                 list.get(a).phoneNumber = phoneNumber_1;
                 System.out.println("�����޸����");
             }
         }
     }


     /*    * ��ѯ����*   */
    public static void searchFunction() throws Exception{//��ѯ����
        System.out.println("������Ҫ��ѯ��������");
        Scanner in_1 = new Scanner(System.in);
        String s1=in_1.nextLine();
        for(int a= 0; a<len;a++){
            if(s1.equals(list.get(a).name)){
                System.out.println(list.get(a).toString());
            }
        }
    }


    /*    * ��ʾ����*   */
    public static void showFunction(){
        for(int i = 0 ;i<len;i++){
            System.out.println(list.get(i).toString());
        }
    }

    /*    * ���湦��*   */
    public static void writeFunction() throws IOException{
        FileWriter writer = new FileWriter("ͨѶ¼����.txt");
        for(int i = 0 ;i<len;i++){
            String []strwriter = new String[len];
            strwriter[i]=list.get(i).toString();
            writer.write(strwriter[i]);
            writer.write("\r\n");
            System.out.println("�ɹ�д��һ�����ݵ� ͨѶ¼����.txt ��");
        }
        writer.close();//�ر�д�������ͷ���Դ
    }

    /*    * ��ȡ����*   */
    public static void readFunction() throws IOException{
        FileReader reader = new FileReader("ͨѶ¼����.txt");
        BufferedReader br = new BufferedReader(reader);
        String str;
        while((str = br.readLine()) != null){//ÿ�ζ�ȡһ���ı����ж��Ƿ񵽴��ļ�β
            System.out.println(str);
        }
        br.close();
    }
}