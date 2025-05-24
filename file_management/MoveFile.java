package file_management;

import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardCopyOption;

public class MoveFile {
    public static void main(String[] args) {
        Path src= Paths.get("myfile.txt");
        Path dest=Paths.get("CopiedFile.txt");
        try {
            Files.move(src, dest, StandardCopyOption.REPLACE_EXISTING);
            System.out.println("Copied Successfully");
        }
        catch (Exception e){
            e.printStackTrace();
        }
    }
}
