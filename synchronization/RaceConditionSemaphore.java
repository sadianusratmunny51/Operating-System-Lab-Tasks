package synchronization;

public class RaceConditionSemaphore {
    static int cnt=0;
    static class Semaphore{
        private volatile int value;
        public Semaphore(int init){
            this.value=init;
        }
        public void waitSema(){
            while(value<=0){}
            value--;

        }
        public void signal(){
            value++;
        }
    }
    static Semaphore semaphore=new Semaphore(1);
    static  class Producer implements Runnable{

        @Override
        public void run() {
            for(int i=1;i<=10;i++){
                semaphore.waitSema();
                int tmp=cnt;
                try{
                    Thread.sleep(100);
                }catch (Exception e){
                   e.printStackTrace();
                }
                cnt=tmp+1;
                System.out.println("Produce cnt:"+cnt);
                semaphore.signal();
                try {
                    Thread.sleep(100);
                } catch (Exception e){
                    e.printStackTrace();
                }
            }
        }
    }
    static class  Consumer implements Runnable{

        @Override
        public void run() {
            for(int i=1;i<=10;i++){
                semaphore.waitSema();
                int tmp=cnt;
                try{
                    Thread.sleep(100);
                }catch (Exception e){
                    e.printStackTrace();
                }
                cnt=tmp-1;
                System.out.println("Consume cnt:"+cnt);
                semaphore.signal();
                try {
                    Thread.sleep(100);
                } catch (Exception e){
                    e.printStackTrace();
                }
            }
        }
    }
    public static void main(String[] args) {
       Producer producer= new Producer();
       Thread producerThread=new Thread(producer);
       Consumer consumer =new Consumer();
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
