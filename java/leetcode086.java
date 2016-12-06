/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
	public ListNode partition(ListNode head, int x) {
		ListNode node1 = new ListNode(0), node2 = new ListNode(0);
		ListNode hoge = node1, fuga = node2;
		while (head != null) {
			if (head.val < x)
				hoge = hoge.next = head;
			else
				fuga = fuga.next = head;
			head = head.next;
		}
		fuga.next = null;
		hoge.next = node2.next;
		return node1.next;
	}
}