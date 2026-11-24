public class LinkedListTest {

    private static class LinkedList<T> {

        private class Node<U> {
            public U val;
            public Node<U> next = null, prev = null;

            public Node(Node<U> node) {
                val = node.val;
                next = node.next;
                prev = node.prev;
            }

            public Node() {
                this(null, null, null);
            }

            public Node(U val, Node<U> next, Node<U> prev) {
                this.val = val;
                this.next = next;
                this.prev = prev;
            }

            public void set(U val, Node<U> next, Node<U> prev) {
                this.val = val;
                this.next = next;
                this.prev = prev;
            }

            @Override 
            public String toString() {
                return val.toString();
            }
        }

        Node<T> head = null, tail = null;
        int size = 0;

        public LinkedList() {
            head = new Node<>();
            tail = head;
        }

        public int length() {
            return size;
        }

        public void add(int pos, T val) {
            if (pos > size) return;

            if (pos == 0) {
                head = new Node<>(val, head, null);
                head.next.prev = head;

            } else if (pos <= size / 2) {
                Node<T> x = head;
                for (int i = 0; i < pos; i++) {
                    x = x.next;
                }
                Node<T> y = new Node<>(val, x, x.prev);
                x.prev.next = y;
                x.prev = y;

            } else {
                Node<T> x = tail;
                for (int i = 0; i < size - pos; i++) {
                    x = x.prev;
                }
                Node<T> y = new Node<>(val, x, x.prev);
                x.prev.next = y;
                x.prev = y;

            }
            size++;
        }

        public void add(T val) {
            add(size, val);
        }

        public T remove(int pos) {
            if (pos >= size) return null;

            T res = null;
            if (pos == 0) {
                res = head.val;
                head = head.next;
                head.prev = null;

            } else if (pos <= size / 2) {
                Node<T> x = head;
                for (int i = 0; i < pos; i++) {
                    x = x.next;
                }
                res = x.val;
                x.prev.next = x.next;
                x.next.prev = x.prev;

            } else {
                Node<T> x = tail;
                for (int i = 0; i < size - pos; i++) {
                    x = x.prev;
                }
                res = x.val;
                x.prev.next = x.next;
                x.next.prev = x.prev;

            }
            size--;
            return res;
        }

        public T remove() {
            return remove(0);
        }

        @Override 
        public String toString() {
            String res = "[";
            Node<T> x = head;
            while (x != tail) {
                res = res + x.toString() + ",";
                x = x.next;
            }
            if (!res.isEmpty() && res.charAt(res.length() - 1) == ',') {
                res = res.substring(0, res.length() - 1);
            }
            return res + "]";
        }
    }

    public static void main(String[] args) {
        int n = 8;
        int[] a = {5, 7, 3, 4, 1, 8, 6, 2};

        LinkedList<Integer> lst = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            lst.add(a[i]);
        }

        System.out.println(lst);
    }
}
