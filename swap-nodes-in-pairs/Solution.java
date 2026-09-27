class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode newHead = new ListNode(0, head);
        ListNode prev = newHead;
        ListNode curr = head;

        while (curr != null && curr.next != null) {
            ListNode a = curr.next;
            ListNode b = curr.next.next;

            a.next = curr;
            curr.next = b;
            prev.next = a;

            prev = curr;
            curr = b;
        }

        return newHead.next;
    }

    ListNode createLinkedList(int[] array) {
        ListNode linkedList = null;
        for (int i : array) {
            ListNode newNode = new ListNode(i, null);
            if (linkedList == null) {
                linkedList = newNode;
            } else {
                ListNode copy = linkedList;
                while (copy.next != null) {
                    copy = copy.next;
                }
                copy.next = newNode;
            }
        }
        return linkedList;
    }

    void printLinkedList(ListNode head) {
        ListNode copy = head;
        while (copy != null) {
            System.out.printf("%d ", copy.val);
            copy = copy.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Solution s = new Solution();

        int[] array = { 1, 2, 3, 4 };
        ListNode head = s.createLinkedList(array);

        ListNode swapped = s.swapPairs(head);
        s.printLinkedList(swapped);
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
