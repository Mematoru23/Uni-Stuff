package Repo;

import Domain.Entity;

import java.io.*;
import java.util.ArrayList;

public class BinRepo<T extends Entity> extends MemRepo<T> {
    private String fileName;

    public BinRepo(String fileName) {
        super();
        this.fileName = fileName;
        try {
            loadFile();
        } catch (IOException | ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    private void loadFile() throws IOException, ClassNotFoundException {
        ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fileName));
        this.entities = (ArrayList<T>) ois.readObject();
    }

    private void saveFile() throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fileName))) {
            oos.writeObject(this.entities);
        }
    }

    @Override
    public void add(T o) throws DuplicateEntityException, IOException {
        super.add(o);
        saveFile();
    }

    @Override
    public void remove(int id) throws Exception {
        super.remove(id);
        saveFile();
    }

}
