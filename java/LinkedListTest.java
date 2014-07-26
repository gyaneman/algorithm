
public class LinkedListTest {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		/*
		LinkedList<String> ll = new LinkedList<String>();
        ll.add("A");
        ll.add("B");
        ll.add("C");
        ll.add("C");
        ll.add(null);
        ll.set(0, "X");  //1文字目を"X"に更新する
        ll.add(1, "Y");  //2文字目に"Y"を挿入する
        ll.remove(2);    //3文字目を削除する

        //LinkedListを1件ずつ取り出し画面に表示する
        Iterator<String> it = ll.iterator();
        while (it.hasNext()) {
            System.out.println((String)it.next());
        }*/
		/*
		LinkedList<String> ll = new LinkedList<String>();
		ListIterator<String> it = ll.listIterator();
		it.add("abc");
		it.previous();
		it.add("cdf");
		
		ListIterator<String> it2 = ll.listIterator();
		while(it2.hasNext()){
			System.out.print(it2.next() + " ");
		}*/
		
		int[] sort_array = {4, 2, 78, 4,1, 4, 65,223, 54,5, 9,21,0,3};
		InsertionListSort sortalg = new InsertionListSort(sort_array);
		sortalg.insertionListSort();
		if(!sortalg.check()){
			System.out.println("faild");
			sortalg.printAll();
		}else
			System.out.println("correct");
	}

}
