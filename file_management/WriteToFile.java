package file_management;

import java.io.File;
import java.io.FileWriter;

public class WriteToFile {
    public static void main(String[] args) {
        File f=new File("myfile.txt");
        if(f.exists()==true) {
            try {
                FileWriter write = new FileWriter("myfile.txt");
                write.write("Hello World");
                write.close();
                System.out.println("Successfully written");

            } catch (Exception e){
                e.printStackTrace();
            }
        }
        else{
            System.out.println("File not found ");
        }
    }
}
