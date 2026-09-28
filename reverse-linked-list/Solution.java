class Solution {
    public ListNode createLinkedList(int[] array) {
        ListNode dummy = new ListNode(0, null);
        ListNode head = dummy;
        for (int i : array) {
            ListNode newNode = new ListNode(i, null);
            dummy.next = newNode;
            dummy = dummy.next;
        }
        return head.next;
    }

    public void printLinkedList(ListNode head) {
        while (head != null) {
            System.out.printf("%d ", head.val);
            head = head.next;
        }
        System.out.println();
    }

    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode last = head;
        while (last != null) {
            ListNode lastNext = last.next;

            last.next = prev;
            prev = last;
            last = lastNext;
        }
        return prev;
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[] array = { 1, 2 };

        ListNode head = s.createLinkedList(array);
        ListNode reversed = s.reverseList(head);
        s.printLinkedList(reversed);
    }
}

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
