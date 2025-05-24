package thread;
//Thread create , join , parameter pass in one code
public class SumOfArrayElements implements Runnable{
    int start;
    int end;
    int result=0;
    int [] arr;
    public SumOfArrayElements(int start, int end,int []arr){
        this.start=start;
        this.end=end;
        this.arr=arr;

    }
    @Override
    public void run() {
        for(int i=start;i<=end;i++){
            result+=arr[i];
        }
    }
    public int getResult(){
        return  result;
    }

    public static void main(String[] args) {
        int []arr={2,4,5,3,7,6};
        SumOfArrayElements s1=new SumOfArrayElements(0,2,arr);
        Thread th1=new Thread(s1);
        SumOfArrayElements s2=new SumOfArrayElements(3,5,arr);
        Thread th2=new Thread(s2);
        th1.start();
        th2.start();
        try{
            th1.join();
            th2.join();
        }
        catch (Exception e){
            e.printStackTrace();
        }
        int sum1=s1.getResult();
        int sum2=s2.getResult();

       int total=sum1+sum2;
        System.out.println("Thread 1 dives sum1="+sum1);
        System.out.println("Thread 2 gives sum2="+sum2);
        System.out.println("Total sum done by main thread:"+total);
    }

}
