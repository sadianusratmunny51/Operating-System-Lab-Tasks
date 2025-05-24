package thread;

public class DeadLock {
    static  final Object lock1=new Object();
    static  final Object lock2=new Object();
     static  class Thread1 implements Runnable{

         @Override
         public void run() {
             synchronized (lock1){
                 System.out.println("Thread1 Holding lock1");
                 try {
                     Thread.sleep(100);
                 }catch (Exception e){
                     e.printStackTrace();
                 }
                 System.out.println("Thread1 waiting for lock2");
                 synchronized (lock2){
                     System.out.println("Thread1 acquired lock2 ");
                 }
             }
         }
     }
    static  class Thread2 implements Runnable{

        @Override
        public void run() {
            synchronized (lock2){
                System.out.println("Thread2 Holding lock2");
                try {
                    Thread.sleep(100);
                }catch (Exception e){
                    e.printStackTrace();
                }
                System.out.println("Thread2 waiting for lock1");
                synchronized (lock1){
                    System.out.println("Thread2 acquired lock1 ");
                }
            }
        }
    }

    public static void main(String[] args) {
        Thread1 t1=new Thread1();
        Thread thread1=new Thread(t1);

        Thread2 t2=new Thread2();
        Thread thread2=new Thread(t2);

        thread1.start();
        thread2.start();

    }
}
