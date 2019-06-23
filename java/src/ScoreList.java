import java.util.Scanner;
public class ScoreList {
    int maxLength = 100;
	int length = 0;
    Score[] data = new Score[maxLength];
    
	Scanner input = new Scanner(System.in);
	
	public ScoreList() {
	
	}
	
	//��Ӽ�¼����
	public void add() {
			if(length < maxLength) {
				data[length] = new Score();
				System.out.print("������ѧ����ѧ�ţ� ");
				data[length].setNum(input.next());
				System.out.print("������ѧ����������");
				data[length].setName(input.next());
				System.out.print("������ѧ���ĳɼ���");
				data[length].setScore(input.nextDouble());
				length++;
				System.out.println("��ӳɹ���");
			}
			else {
				System.out.println("���ʧ�ܣ�");
			}
	}
	
	//��ʾ�ɼ�������
	public void transcript() {
		System.out.println("=====================================");
		System.out.println(" ѧ��                     ����                      �ɼ� ");
		for(int i = 0; i < length; i++) {
			System.out.println(data[i].num + "\t" + data[i].name + "\t" + "\t" + data[i].score);
		}
		System.out.println("=====================================\n");
	}
	
	//�ɼ��Ӹ��������򷽷�
	public void sort() {
		Score temp = new Score();
		for(int i = 1; i < length; i++) {
			for(int j = 0; j < length - i; j++) {
				if(data[j].score < data[j + 1].score) { //ð�ݷ�����
					temp = data[j]; data[j] = data[j + 1]; data[j + 1] = temp;
				}
 
			}
		}
	}
	
	//ƽ���֡������Сֵ����
	public void average() {
		double sum = 0.0;
		double max = 0.0;
		double min = 100.0;
		for(int i = 0; i < length; i++) {
			sum += data[i].score;
			max = max > data[i].score ? max : data[i].score;
			min = min < data[i].score ? min : data[i].score; //��Ŀ���㷨
		}
		System.out.printf("���ſε�ƽ���ɼ�Ϊ: %.2f\n", sum/length);
		System.out.println("��߷�Ϊ: " + max + "\n" + "��ͷ�Ϊ: " + min + "\n");
	}
	
	//ɾ��ѧ����¼����
	public void delete() {
		System.out.print("��������Ҫɾ����Ϣ��ѧ����ѧ��: ");
    	String number1 = input.next();
		int i, flag = length;
		for(i = 0; i < length; i++) {
			if(number1.equals(data[i].num)) {
				flag = i; break;
			}
			}
		if(i == length) {
			System.out.println("���޴��ˣ���˶Ժ��������� \n");
			delete();
		}
		else {
			for(int j = flag; j < length; j++) {
				data[j] = data[j + 1];
			}
			System.out.println("ɾ���ɹ���\n");
			length -= 1; //����1�ᱨ����Խ��Ĵ���
		}
	}
	
	
	//��ѯĳ��ѧ����Ϣ����
	public void inquire() {
		System.out.print("��������Ҫ��ѯ�ɼ���ѧ����ѧ�ţ�");
    	String number2 = input.next();
		int i;
		for(i = 0; i < length; i++) {
			if(number2.equals(data[i].num)) {
				System.out.println("====================================");
				System.out.println(" ѧ��                     ����                      �ɼ� ");
				System.out.println(data[i].num + "\t" + data[i].name + "\t" + "\t" + data[i].score);
				System.out.println("====================================\n");
				break;
			}
			}
		if(i == length) {
			System.out.println("���޴��ˣ���˶Ժ���������ѧ�� \n");
			inquire();
		}
	}
	
	//�޸�ѧ����Ϣ����
	public void recompose() {
		System.out.print("��������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�");
    	String number3 = input.next();
		int i;
		for(i = 0; i < length; i++) {
			if(number3.equals(data[i].num)) {
				System.out.println("�������ѧ���µ�ѧ�ţ������ͳɼ���");
				data[i].setNum(input.next());
				data[i].setName(input.next());
				data[i].setScore(input.nextDouble());
				System.out.println("�޸ĳɹ���\n");
				break;
			}
			}
		if(i == length) {
			System.out.println("���޴��ˣ���˶Ժ���������ѧ��\n");
			recompose();
		}
	}
}

