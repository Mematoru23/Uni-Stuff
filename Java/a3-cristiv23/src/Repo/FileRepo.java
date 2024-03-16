package Repo;

import Domain.Cake;
import Domain.Entity;
import Domain.IEntityFactory;

import java.io.*;
import java.util.*;

public class FileRepo<T extends Entity> extends MemRepo<T>{
    private String fileName;
    private IEntityFactory<T> entityFactory;

    public FileRepo(String fName, IEntityFactory<T> entityFactory) throws FileNotFoundException, DuplicateEntityException {
        this.fileName = fName;
        this.entityFactory = entityFactory;
        readFromFile();
    }

    private void readFromFile() throws DuplicateEntityException {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            Scanner scanner = new Scanner(reader);
            while (scanner.hasNext()) {
                String line = scanner.nextLine();
                T entity = entityFactory.createEntity(line);
                super.add(entity);
            }
            scanner.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void saveData() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            for (T item : super.entities) {
                writer.write(item.toString());
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void add(T entity) throws DuplicateEntityException, IOException {
        super.add(entity);
        saveData();
    }

    public void modify(T entity) throws Exception {
        super.modify(entity);
        saveData();
    }

    public void remove(int id) throws Exception {
        super.remove(id);
        saveData();
    }
}
