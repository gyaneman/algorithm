import java.util.LinkedList;
import java.util.ListIterator;

public class InsertionListSort {
	int[] sort_array;
	
	public InsertionListSort(int[] sort_array){
		this.sort_array = sort_array;
	}
	
	public void insertionListSort(){
		LinkedList<Element> list = new LinkedList<Element>();
		
		for(int i = 0; i < this.sort_array.length; i++){
			ListIterator<Element> ite = list.listIterator();
			boolean flg = true;
			while(ite.hasNext()){
				System.out.print(".");
				Element e = ite.next();
				//if(compareValue(e.getValue(), this.sort_array[i])){
				if(compareValue(this.sort_array[i], e.getValue())){
					System.out.print("1");
					ite.previous();
					ite.add(new Element(this.sort_array[i], ""));
					flg = false;
					break;
				}
			}
			if(!ite.hasNext() && flg){
				System.out.print("2");
				ite.add(new Element(this.sort_array[i], ""));
			}
		}
		System.out.println();
		
		debug(list);
		int i = 0;
		ListIterator<Element> ite = list.listIterator();
		while(ite.hasNext()){
			this.sort_array[i++] = ite.next().getValue();
		}
	}
	
	private int compare = 0;
	private boolean compareValue(int a, int b){
		this.compare++;
		return a < b;
	}
	
	public int getCompareValue(){
		return this.compare;
	}
	
	public boolean check(){
		for(int i = 1; i < this.sort_array.length; i++){
			if(this.sort_array[i] < this.sort_array[i-1])
				return false;
		}
		return true;
	}
	
	public void printAll(){
		for(int i = 0; i < this.sort_array.length; i++){
			System.out.print(this.sort_array[i] + " ");
		}
		System.out.println();
	}
	
	private void debug(LinkedList<Element> ll){
		System.out.println("debug");
		for(ListIterator<Element> ite = ll.listIterator(); ite.hasNext();){
			System.out.print(ite.next().getValue() + " ");
		}
	}
}
