class Solution {
    /**
     * Remove n-th element from the end of the linked list
     *
     * @param head linked list head
     * @param n    n-th element from the end
     * @return head of new linked list
     */
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode copy = new ListNode(0, head);

        ListNode temp = copy;
        while (n >= 0) {
            temp = temp.next;
            n--;
        }
        ListNode nth = copy;
        while (temp != null) {
            temp = temp.next;
            nth = nth.next;
        }
        nth.next = nth.next.next;

        return copy.next;
    }

    /**
     * Create linked list based on array
     *
     * @param array values of new linked list
     * @return linked list head
     */
    private ListNode createLinkedList(int[] array) {
        ListNode head = null;
        for (int i = 0; i < array.length; i++) {
            ListNode newNode = new ListNode(array[i], null);
            if (head == null) {
                head = newNode;
            } else {
                ListNode temp = head;
                while (temp.next != null) {
                    temp = temp.next;
                }
                temp.next = newNode;
            }
        }
        return head;
    }

    /**
     * Print linked list values
     *
     * @param head linked list head
     * @return void
     */
    private void printLinkedList(ListNode head) {
        ListNode temp = head;
        while (temp != null) {
            System.out.printf("%d ", temp.val);
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] array = { 1, 2, 3, 4 };
        int n = 4;

        Solution s = new Solution();
        ListNode head = s.createLinkedList(array);
        s.printLinkedList(head);
        ListNode newHead = s.removeNthFromEnd(head, n);
        s.printLinkedList(newHead);
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
