package Service;

import Repo.DuplicateEntityException;
import Repo.IRepo;
import Domain.Cake;

import java.io.IOException;
import java.util.Collection;

public class CakeService {
    IRepo<Cake> repository;

    public CakeService(IRepo<Cake> repository) {
        this.repository = repository;
    }

    public void addCake(int id, String cakeType) throws DuplicateEntityException, IOException {
        repository.add(new Cake(id, cakeType));
    }

    public void removeCake(int id) throws Exception {
        repository.remove(id);
    }

    public void modifyCake(int id, String cakeType) throws Exception
    {
        repository.modify(new Cake(id, cakeType));
    }

    public Cake findById(int id)
    {
        return repository.findById(id);
    }

    public Collection<Cake> getAll()
    {
        return repository.getAll();
    }
}
