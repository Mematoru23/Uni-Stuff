package src.Repo;

import src.Domain.Entity;
import src.Domain.IEntityFactory;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileRepo<T extends Entity> extends MemRepo<T>{
    private String fileName;
    private IEntityFactory<T> entityFactory;

    public FileRepo(String fName, IEntityFactory<T> entityFactory) throws FileNotFoundException, DuplicateEntityException {
        this.fileName = fName;
        this.entityFactory = entityFactory;
        readFromFile();
    }

    private void readFromFile() throws FileNotFoundException, DuplicateEntityException {
        File file = new File(fileName);
        Scanner scanner = new Scanner(file);
        while (scanner.hasNext())
        {
            String line = scanner.nextLine();
            T entity = entityFactory.createEntity(line);
            add(entity);
        }
        scanner.close();
    }

    // to be continued
    private void saveToFile() {
        try (FileWriter writer = new FileWriter(fileName)) {
            for (T entity : getAll()) {
                String entityInfo = "";
                writer.write(entityInfo + System.lineSeparator());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
