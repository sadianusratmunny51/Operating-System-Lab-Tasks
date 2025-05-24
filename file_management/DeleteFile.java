package file_management;

import java.io.File;

public class DeleteFile {
    public static void main(String[] args) {
        File f=new File("myfile.txt");
        if(f.exists()==true){
            try{
                if(f.delete()==true){
                    System.out.println("File deleted successfully");
                }

            }catch (Exception e){
                e.printStackTrace();
            }
        }
        else{
            System.out.println("File doesn't exists");
        }
    }
}
