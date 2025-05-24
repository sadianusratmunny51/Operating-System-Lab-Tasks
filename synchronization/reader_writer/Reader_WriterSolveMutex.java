package synchronization.reader_writer;

public class Reader_WriterSolveMutex {

    static class SharedData {
        int value = 0;

        public synchronized void write(int newValue) {
            value = newValue;
            System.out.println("Writer wrote value: " + value);
        }

        public synchronized void read() {
            System.out.println("Reader read value: " + value);
        }
    }

    static class Writer implements Runnable {
        SharedData data;

        public Writer(SharedData data) {
            this.data = data;
        }

        @Override
        public void run() {
            for (int i = 1; i <= 5; i++) {
                data.write(i);
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class Reader implements Runnable {
        SharedData data;

        public Reader(SharedData data) {
            this.data = data;
        }

        @Override
        public void run() {
            for (int i = 1; i <= 5; i++) {
                data.read();
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        SharedData shared = new SharedData();

        Thread writerThread = new Thread(new Writer(shared));
        Thread readerThread1 = new Thread(new Reader(shared));
        Thread readerThread2 = new Thread(new Reader(shared));

        writerThread.start();
        readerThread1.start();
        readerThread2.start();
    }
}
