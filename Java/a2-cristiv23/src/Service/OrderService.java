package src.Service;

import src.Domain.Cake;
import src.Domain.Order;
import src.Repo.DuplicateEntityException;
import src.Repo.IRepo;

import java.util.Collection;
import java.util.List;

public class OrderService {
    IRepo<Order> repository;

    public OrderService(IRepo<Order> repository) {
        this.repository = repository;
    }

    public void addOrder(int id, List<Cake> lc, String date) throws DuplicateEntityException {
        repository.add(new Order(id, lc, date));
    }

    public void removeOrder(int id) throws Exception {
        repository.remove(id);
    }

    public void modifyCake(int id, List<Cake> cakes, String date) throws Exception
    {
        repository.modify(new Order(id, cakes, date));
    }

    public Collection<Order> getAll()
    {
        return repository.getAll();
    }
}
