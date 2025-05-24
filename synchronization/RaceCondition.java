package synchronization;

public class RaceCondition {
    static  int cnt=0;
    static class Producer  implements  Runnable{

        @Override
        public void run() {
            for(int i=1;i<=10;i++){
                int tmp=cnt;
                try{
                    Thread.sleep(100);
                } catch (Exception e){
                    e.printStackTrace();
                }
                cnt=tmp+1;
                System.out.println("Producer count="+cnt);
                try{
                    Thread.sleep(100);
                }catch (Exception e){
                    e.printStackTrace();
                }
            }
        }
    }
    static class Consumer  implements  Runnable{

        @Override
        public void run() {
            for(int i=1;i<=10;i++){
                int tmp=cnt;
                try{
                    Thread.sleep(100);
                } catch (Exception e){
                    e.printStackTrace();
                }
                cnt=tmp-1;
                System.out.println("Consumer count="+cnt);
                try{
                    Thread.sleep(100);
                }catch (Exception e){
                    e.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        Producer producer=new Producer();
        Thread producerThread=new Thread(producer);
        Consumer consumer=new Consumer();
        Thread consumerThread=new Thread(consumer);
        producerThread.start();
        consumerThread.start();
        try {
            producerThread.join();
            consumerThread.join();
        }catch (Exception e){
            e.printStackTrace();
        }

        System.out.println("Final count="+cnt);

    }

}
