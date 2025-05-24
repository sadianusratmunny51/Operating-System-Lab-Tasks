package process;

public class ProcessTermination {
    public static void main(String[] args) {
        try{
            Process p=Runtime.getRuntime().exec("taskkill /F /IM notepad.exe");
            p.waitFor();
            System.out.println();
            System.out.println("Notepad Process terminated");

        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
