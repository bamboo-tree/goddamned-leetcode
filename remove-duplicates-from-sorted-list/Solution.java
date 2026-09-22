class Solution {

    public void printLinkedList(ListNode head) {
        while (head != null) {
            System.out.printf("%d ", head.val);
            head = head.next;
        }
        System.out.println();
    }

    // im dumb :(
    public ListNode deleteDuplicates(ListNode head) {
        ListNode temp = head;

        while (temp != null && temp.next != null) {
            if (temp.val == temp.next.val) {
                temp.next = temp.next.next;
            } else {
                temp = temp.next;
            }
        }

        return head;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] array = { 1, 1, 2, 3, 3 };

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

        System.out.println("Initial linked list:");
        solution.printLinkedList(head);

        ListNode newLinkedList = solution.deleteDuplicates(head);
        System.out.println("Removed duplicates:");
        solution.printLinkedList(newLinkedList);

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
