package synchronization.reader_writer;

public class Reader_WriterRaceCondition {

    static class SharedData {
        int value = 0;
    }

    static class Writer implements Runnable {
        SharedData data;

        public Writer(SharedData data) {
            this.data = data;
        }

        @Override
        public void run() {
            for (int i = 0; i < 5; i++) {
                data.value++;
                System.out.println("Writer updated value to " + data.value);
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
            for (int i = 0; i < 5; i++) {
                System.out.println("Reader read value as " + data.value);
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

