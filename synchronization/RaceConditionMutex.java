package synchronization;

public class RaceConditionMutex {
   static int cnt=0;
   static  class Mutex{
       private volatile  boolean available=true;
       public void acquire(){
           while(available==false){}
           available=false;
       }
       public  void release(){
           available=true;
       }
   }
   static  Mutex mutex=new Mutex();
   static class Producer implements Runnable{

       @Override
       public void run() {
           for(int i=1;i<=10;i++){
               mutex.acquire();
               int tmp=cnt;
               try {
                   Thread.sleep(100);
               }catch (Exception e){
                   e.printStackTrace();
               }
               cnt=tmp+1;
               System.out.println("Produce count="+cnt);
               mutex.release();
               try {
                   Thread.sleep(100);
               }catch (Exception e){
                   e.printStackTrace();
               }
           }
       }
   }
   static class Consumer implements Runnable{

       @Override
       public void run() {
           for(int i=1;i<=10;i++){
               mutex.acquire();
               int tmp=cnt;
               try {
                   Thread.sleep(100);
               }catch (Exception e){
                   e.printStackTrace();
               }
               cnt=tmp-1;
               System.out.println("Consume count="+cnt);
               mutex.release();
               try {
                   Thread.sleep(100);
               }catch (Exception e){
                   e.printStackTrace();
               }
           }
       }
   }

    public static void main(String[] args) {
        Producer producer = new Producer();
        Thread producerThread=new Thread(producer);

        Consumer consumer = new Consumer();
        Thread consumerThread=new Thread(consumer);


        producerThread.start();
        consumerThread.start();
        try{
            producerThread.join();
            consumerThread.join();
        }catch (Exception e){
            e.printStackTrace();
        }
        System.out.println();
        System.out.println("Final count="+cnt);


    }
}
