package thread;

public class CreateAndJoinThread implements Runnable {

    @Override
    public void run(){
        System.out.println("Thread Started");
    }

    public static void main(String[] args) {
        CreateAndJoinThread t=new CreateAndJoinThread();
        Thread th=new Thread(t);
        th.start();
        try{
            th.join();
        }
        catch (Exception e){
            e.printStackTrace();
        }
        System.out.println("Thread Finished");
    }

}
