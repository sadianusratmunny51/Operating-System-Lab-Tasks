package file_management;

import java.io.File;

public class CreateFile {
    public static void main(String[] args) {
        try {
            File f=new File("myfile.txt");
            if(f.createNewFile()==true){
                System.out.println("File created .");
                System.out.println("file name : "+f.getName());
            }
            else{
                System.out.println("File already exists");
            }

        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
