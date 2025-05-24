package thread;

public class PassingParameter implements Runnable{
    String name;
    public PassingParameter (String  name){
        this.name=name;
    }
    @Override
    public void run() {
        System.out.println("the Thread name is :"+name);
    }

    public static void main(String[] args) {
        PassingParameter t=new PassingParameter("thread -0");
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
