EdukitIIIʵ�������� MDK���̵Ļ����ļ���֯�ṹ��

   ������
      	|----Startup 	�������� ��S3C2410A.S��,��ע�����ʹ�������������������룬
      	|               MDK�Զ����ɵ�����������Ҫ�޸Ĳſ�ʹ����ʵ�����ϡ�
      	|----Common		���ô��루2410lib.c,sys_init.c��
      	|
		|----Source     �û�Դ����
      	|
		|----Script     �ű��ļ��������ļ�ini����ɢ�����ļ�sct�ȣ�
        |
        |----ReadMe     ����˵���ĵ�

===========================================================================================
ʵ���������ļ�Ŀ¼�ṹ:
	3.1_asm1
	3.2_asm2
	3.3_thumbcode
	3.4_armmode
	3.5_c1
	3.6_c2
	3.7_explasm
	3.8_interwork
	4.1_memory_test
	4.2_led_test
	4.3_int_test
	4.4_uart_test
	4.5_rtc_test
	4.6_8led_test
	4.7_watchdog_test
	5.1_color_lcd
	5.2_keyboard_test
	5.3_touchscreen_test
	6.1_iic_test
	6.2_tftp_test
	6.3_iis_test
	6.4_usb_test
	7.1_adc_test
	7.2_pwm_test
        	����Ŀ¼�ֱ��Ӧʵ��̸̳��½ڵ�����.
	common  �ṩ�������̵Ĺ����ļ�;
	tools	�ṩһЩ������������Ҫ�Ĺ������;
        	����Ŀ¼�ֱ��Ӧʵ��̸̳��½ڵ�����.
============================================================================================
���̵�Option����: 
    Device��ѡ��Samsung-S3C44B0X;
	Target������ 	off-chip  ROM1: 0x0,0x200000  Startup
                 	off-chip  RAM1: 0xC000000,0x800000
		     		on-chip   IRAM1:0x10000000,0x2000
	Output�������ļ���Ϊ��ǰĿ¼�µ�/obj;
	Listing�������ļ���Ϊ��ǰĿ¼�µ�/lst;
	C/C++��ASM����includ path �ı����н�commonĿ¼����·������;
	Linker������Scatter File,�����RAM��������ѡ��"RuninRAM.SCT",  
        �����FLash��������ѡ��"RuninFLash.SCT"(�������ļ�����commonĿ¼��);
	��ע����Script�ļ���������������ļ�ʱ����ָ����Ϊ�ı��ļ�,�����ǻ�������ļ�.

	Debug��ѡ�� use Simulator�����PC�Ͻ����������;
	ѡ�� use ULINK ARM Debugger�����Ŀ�����������;
	ѡ�� Run to main ������Զ����е�main()��������ͣ������Run��ť��F5������ż������С�
        ��Initialization�ı����пɼ����������ű��ļ�,�԰�������.
	Utilities��ѡ�� ULINK ARM Debugger,���setting��ť������д����
	RAM for Algorithm ����Start: 0x10000000,Size 0x800
	Programming Algorithmѡ�� AM29F160DB Flash Ext Flash 16-bit  2M

=============================================================================================
���������ļ�(INI)����ʹ������������������ʱ,�����Ǽ������õ�����,�û����Ը��ݵ�����Ҫ��д�Լ��ĵ��������ļ�. 
	pc=0xC000000    		
		��PCָ��0xC000000��;(������RAM������ʱ��ָ��0xC000000,�����Flash��������ָ��0x000)
	map 0x01c00000, 0x02000000 read write
		ָ��ĳ�δ洢���������Ϊ�ɶ�,��д,��ִ��;
	Go startaddr, stopaddr
		�����startaddr��ʼִ��,��stopaddr��ֹͣ;��ʼ��ַ������ȱʡ. Ҳ���ú�������ʾ��ַ���� G , main

==============================================================================================
��ɢ�����ļ�(sct)���ڼ���ӳ���ļ����洢�ռ���,MDK�ɸ��ݴ洢�����Զ�����,����Ӧ�ó�������Ҫ���б�д. 
��������RAM�����г����SCT��:

LR_ROM1 0x0C000000         
{                                 ; load region
  ER_ROM1 0x0C000000 0x0200000  
  {                               ; load address = execution address
   *.o (RESET, +First)
   *(InRoot$$Sections)
   .ANY (+RO)
  }
  RW_RAM1 +0  
  {                               ; RW data
   .ANY (+RW +ZI)
  }
}

��������Flash�����г����SCT�ļ�: 

LR_ROM1 0x00000000         
{                              ; load region
  ER_ROM1 0x00000000 0x0200000 
   {                           ; load address = execution address
   *.o (RESET, +First)
   *(InRoot$$Sections)
   .ANY (+RO)
   }
  RW_RAM1 0x0C000000 0x800000  
  {                             ; RW data
   .ANY (+RW +ZI)
  }
}
============================================================================================







       