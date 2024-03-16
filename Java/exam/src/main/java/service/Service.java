package service;

import entity.AbstractEntity;
import repository.InterfaceRepo;

import java.io.IOException;
import java.sql.SQLException;
import java.util.Collection;

public class Service<T extends AbstractEntity> {
    private InterfaceRepo<T> repo;

    public Service(InterfaceRepo<T> repo) {
        this.repo = repo;
    }

    public void add(T item) throws IOException, SQLException {
        this.repo.add(item);
    }

    public void update(T item, String id) throws IOException, SQLException {
        this.repo.update(item, id);
    }

    public void delete(String index) throws IOException, SQLException {
        this.repo.delete(index);
    }

    public Collection<T> getAll() throws SQLException {
        return this.repo.getAll();
    }
}