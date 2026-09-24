class Solution {
    /**
     * Remove elements from linked list
     *
     * @param head linked list head
     * @param val  value to remove from linked list
     * @return linked list head without {@value val}
     */
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(val + 1, head);
        ListNode temp = dummy;
        while (temp != null) {
            if (temp.next != null && temp.next.val == val) {
                temp.next = temp.next.next;
            } else {
                temp = temp.next;
            }
        }
        return dummy.next;
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
        int[] array = { 1, 2, 6, 3, 4, 5, 6 };
        int val = 6;

        Solution s = new Solution();
        ListNode head = s.createLinkedList(array);
        s.printLinkedList(head);
        ListNode newHead = s.removeElements(head, val);
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
