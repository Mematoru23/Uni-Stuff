package Repo;

import Domain.Entity;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

public class MemRepo<T extends Entity> implements IRepo<T> {
    List<T> entities = new ArrayList<>();

    @Override
    public void add(T entity) throws DuplicateEntityException, IOException {
        if (entity == null)
            throw new IllegalArgumentException("Entity can't be null");
        if (findById(entity.getId()) != null)
            throw new DuplicateEntityException("Entity already exists!");
        entities.add(entity);
    }

    @Override
    public void remove(int id) throws Exception {
        for (T entity : entities)
        {
            if (entity.getId() == id)
            {
                entities.remove(entity);
                return;
            }
        }
        throw new Exception("No object found to delete");
    }

    public void modify(T newE) throws Exception {
        for (int i = 0; i < entities.size(); i++)
        {
            if (entities.get(i).getId() == newE.getId())
            {
                entities.set(i, newE);
                return;
            }
        }
        throw new Exception("No object found to modify");
    }

    @Override
    public T findById(int id) {
        for (T entity : entities)
        {
            if (entity.getId() == id)
            {
                return entity;
            }
        }
        return null;
    }

    @Override
    public Collection<T> getAll() {
        return new ArrayList<T>(entities);
    }

    @Override
    public Iterator<T> iterator() {
        return new ArrayList<T>(entities).iterator();
    }
}
