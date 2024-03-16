package repository;
import entity.AbstractEntity;
import java.io.IOException;
import java.util.*;

public class AbstractRepo<T extends AbstractEntity> implements InterfaceRepo<T> {

    protected List<T> data = new ArrayList<>();

    @Override
    public void add(T item) throws IOException{
        int maxId = 0;
        if(data.size() > 0)
        {
            maxId = 0;
            for (T p : data) {
                if (p.getUniqueID() > maxId) {
                    maxId = p.getUniqueID();
                }
            }
            int id = maxId + 1;
            item.setUniqueID(id);
            data.add(item);
        }
        else{
            item.setUniqueID(100);
            data.add(item);
        }

    }

    @Override
    public void update(T newItem, String id) throws IOException {
        for (int i = 0; i < data.size(); i++) {
            T item = data.get(i);
            if (item instanceof AbstractEntity entity) {
                if (entity.getUniqueID().equals(id)) {
                    data.set(i, newItem);
                    return;
                }
            }
        }
        throw new IllegalArgumentException("Item with ID " + id + " not found");
    }

    @Override
    public void delete(String id) throws IOException {
        T itemToDelete = null;
        for (T item : data) {
            if (item instanceof AbstractEntity entity) {
                if (entity.getUniqueID().equals(id)) {
                    itemToDelete = item;
                    break;
                }
            }
        }

        if (itemToDelete != null) {
            data.remove(itemToDelete);
        } else {
            throw new IllegalArgumentException("Item with ID " + id + " not found");
        }
    }

    public boolean existsByID(String id) {
        for (T item : data) {
            if (item instanceof AbstractEntity entity) {
                if (entity.getUniqueID().equals(id)) {
                    return true;
                }
            }
        }
        return false;
    }

    @Override
    public Collection<T> getAll() {
        return new ArrayList<T>(data);
    }

}