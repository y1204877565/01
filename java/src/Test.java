import java.util.Scanner;
public class Test {
	public static void main(String[] args) {
		String choice = "1";
		ScoreList studentScoreList = new ScoreList();
		System.out.println("**********ѧ���ɼ�����ϵͳ********");
		while(choice.equals("0") == false) {
			System.out.println("1.�鿴ѧ���ɼ���");
			System.out.println("2.���ѧ���ɼ���¼");
			System.out.println("3.�޸�ѧ���ɼ���¼");
			System.out.println("4.ɾ��ѧ���ɼ���¼");
			System.out.println("5.�鿴ĳλѧ���ɼ���¼");
			System.out.println("6.ͳ�����ſ�ƽ���֡���߷ֺ���ͷ�");
			System.out.println("7.���ɼ��Ӹ��������򣬲����");
			System.out.println("0.�˳�����");
			System.out.print("Enter your choice: ");
			choice = new Scanner(System.in).next();
	    	
			switch(choice) {
			    case "0": 
			    	System.out.println("лл����ʹ�ã���ӭ�´ι��٣�\n" + "**********���������������**********"); 
			        break;
			    
			    case "1":
			    	studentScoreList.transcript();
			    	System.out.println("����������Ҫʲô����\n");
			    	break;
				
			    case "2":
			    	int i = 1;
			    	do {
			    	studentScoreList.add();
			    	System.out.println("\n�Ƿ������ӣ�" + "\n" + "0.��" + "\n" + "1.��");
			    	i = new Scanner(System.in).nextInt();
			    	}while(i == 1);
			    	System.out.println("����������Ҫʲô����\n");
			    	break;
			    	
			    case "3": 
			    	studentScoreList.recompose();
			    	System.out.println("����������Ҫʲô����\n");
			    	break;
				
			    case "4":
			    	studentScoreList.delete();
			    	System.out.println("����������Ҫʲô����\n");
			    	break;
				
			    case "5":
			    	studentScoreList.inquire();
			    	System.out.println("����������Ҫʲô����\n");
			    	break;
				
			    case "6":
			    	studentScoreList.average();
			    	System.out.println("����������Ҫʲô����\n");
			    	break;
				
			    case "7":
			    	studentScoreList.sort();
			    	studentScoreList.transcript();
			    	System.out.println("����������Ҫʲô����\n");
			    	break;
				
				default: 
					System.out.println("Invalid input! Please enter again."); 
				    break;
			}
			
		}
	}
 
}

