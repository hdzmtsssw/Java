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

    /*    * 界面设计 *    */
    public tele(){
        Container c = getContentPane(); //定义一个顶级容器c
        JPanel jp = new JPanel();   //新建JPanel面板--jp
        JButton button1 = new JButton("添加联系人");
        JButton button2 = new JButton("删除联系人");
        JButton button3 = new JButton("修改联系人");
        JButton button4 = new JButton("查找联系人");
        JButton button5 = new JButton("显示所有联系人");
        JButton button6 = new JButton("保存联系人到本地");
        JButton button7 = new JButton("读取本地联系人");
        jp.setLayout(new GridLayout(2,4,30,50));
        jp.add(button1);
        jp.add(button2);
        jp.add(button3);
        jp.add(button4);
        jp.add(button5);
        jp.add(button6);
        jp.add(button7);
        c.add(jp);//将JPanel面板jp添加到顶级容器c中
        setSize(700,150);
        setTitle("*通讯录管理系统*");
        setVisible(true);
        setResizable(false);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);


        /*  *按键响应 *  */
        button1.addActionListener(new ActionListener(){//添加功能实现
            public void actionPerformed(ActionEvent arg0){
                Infro.addFunction();
            }
        });
        button2.addActionListener(new ActionListener(){//删除功能实现
            public void actionPerformed(ActionEvent arg0){
                Infro.deleteFunction();
            }
        });
        button3.addActionListener(new ActionListener(){//修改功能实现
            public void actionPerformed(ActionEvent arg0){
                Infro.reditFunction();
            }
        });
        button4.addActionListener(new ActionListener(){//查询功能实现
            public void actionPerformed(ActionEvent arg0){
                try {
                    Infro.searchFunction();
                } catch (Exception e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
        });
        button5.addActionListener(new ActionListener(){//显示功能实现
            public void actionPerformed(ActionEvent arg0){
                Infro.showFunction();
            }
        });
        button6.addActionListener(new ActionListener(){//保存功能实现
            public void actionPerformed(ActionEvent arg0){
                try {
                    Infro.writeFunction();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });
        button7.addActionListener(new ActionListener(){//读取功能实现
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