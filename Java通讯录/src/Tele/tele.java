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

public class tele extends JFrame {

    /*    * ������� *    */
    public tele(){
        Container c = getContentPane(); //����һ����������c
        JPanel jp = new JPanel();   //�½�JPanel���--jp
        JButton button1 = new JButton("�����ϵ��");
        JButton button2 = new JButton("ɾ����ϵ��");
        JButton button3 = new JButton("�޸���ϵ��");
        JButton button4 = new JButton("������ϵ��");
        JButton button5 = new JButton("��ʾ������ϵ��");
        JButton button6 = new JButton("������ϵ�˵�����");
        JButton button7 = new JButton("��ȡ������ϵ��");
        jp.setLayout(new GridLayout(2,4,30,50));
        jp.add(button1);
        jp.add(button2);
        jp.add(button3);
        jp.add(button4);
        jp.add(button5);
        jp.add(button6);
        jp.add(button7);
        c.add(jp);//��JPanel���jp��ӵ���������c��
        setSize(700,150);
        setTitle("*ͨѶ¼����ϵͳ*");
        setVisible(true);
        setResizable(false);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);


        /*  *������Ӧ *  */
        button1.addActionListener(new ActionListener(){//��ӹ���ʵ��
            public void actionPerformed(ActionEvent arg0){
                Infro.addFunction();
            }
        });
        button2.addActionListener(new ActionListener(){//ɾ������ʵ��
            public void actionPerformed(ActionEvent arg0){
                Infro.deleteFunction();
            }
        });
        button3.addActionListener(new ActionListener(){//�޸Ĺ���ʵ��
            public void actionPerformed(ActionEvent arg0){
                Infro.reditFunction();
            }
        });
        button4.addActionListener(new ActionListener(){//��ѯ����ʵ��
            public void actionPerformed(ActionEvent arg0){
                try {
                    Infro.searchFunction();
                } catch (Exception e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
        });
        button5.addActionListener(new ActionListener(){//��ʾ����ʵ��
            public void actionPerformed(ActionEvent arg0){
                Infro.showFunction();
            }
        });
        button6.addActionListener(new ActionListener(){//���湦��ʵ��
            public void actionPerformed(ActionEvent arg0){
                try {
                    Infro.writeFunction();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        button7.addActionListener(new ActionListener(){//��ȡ����ʵ��
            public void actionPerformed(ActionEvent arg0){
                try {
                    Infro.readFunction();
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
        });
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        new tele();
        Infro a = new Infro("", "", "", "", "", "");
    }

}