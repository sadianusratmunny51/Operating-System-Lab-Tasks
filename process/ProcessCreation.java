package process;

public class ProcessCreation {
    public static void main(String[] args) {
        try{
            Process p=new ProcessBuilder("notepad.exe").start();
            System.out.println("Process in note pad started");
            Thread.sleep(1000);


        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
