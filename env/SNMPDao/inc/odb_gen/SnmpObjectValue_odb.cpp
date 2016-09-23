// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "SnmpObjectValue_odb.h"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/mssql/traits.hxx>
#include <odb/mssql/database.hxx>
#include <odb/mssql/transaction.hxx>
#include <odb/mssql/connection.hxx>
#include <odb/mssql/statement.hxx>
#include <odb/mssql/statement-cache.hxx>
#include <odb/mssql/simple-object-statements.hxx>
#include <odb/mssql/container-statements.hxx>
#include <odb/mssql/exceptions.hxx>
#include <odb/mssql/simple-object-result.hxx>

namespace odb
{
  // SnmpObjectValue
  //

  const char alias_traits<  ::SnmpObject,
    id_mssql,
    access::object_traits_impl< ::SnmpObjectValue, id_mssql >::snmpObjectFk_tag>::
  table_name[] = "[snmpObjectFk]";

  const char alias_traits<  ::SnmpObjectType,
    id_mssql,
    access::object_traits_impl< ::SnmpObjectValue, id_mssql >::snmpObjectTypeFk_tag>::
  table_name[] = "[snmpObjectTypeFk]";

  const char alias_traits<  ::MonitorHistory,
    id_mssql,
    access::object_traits_impl< ::SnmpObjectValue, id_mssql >::monitorHistoryFk_tag>::
  table_name[] = "[monitorHistoryFk]";

  struct access::object_traits_impl< ::SnmpObjectValue, id_mssql >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      mssql::connection&,
      image_type&,
      id_image_type&,
      mssql::binding&,
      mssql::binding&)
    {
    }
  };

  access::object_traits_impl< ::SnmpObjectValue, id_mssql >::id_type
  access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  id (const id_image_type& i)
  {
    mssql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mssql::value_traits<
          long unsigned int,
          mssql::id_bigint >::set_value (
        id,
        i.id_value,
        i.id_size_ind == SQL_NULL_DATA);
    }

    return id;
  }

  access::object_traits_impl< ::SnmpObjectValue, id_mssql >::id_type
  access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  id (const image_type& i)
  {
    mssql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      mssql::value_traits<
          long unsigned int,
          mssql::id_bigint >::set_value (
        id,
        i.snmpObjectValueId_value,
        i.snmpObjectValueId_size_ind == SQL_NULL_DATA);
    }

    return id;
  }

  void access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  bind (mssql::bind* b,
        image_type& i,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    std::size_t n (0);

    // snmpObjectValueId_
    //
    if (sk != statement_insert && sk != statement_update)
    {
      b[n].type = mssql::bind::bigint;
      b[n].buffer = &i.snmpObjectValueId_value;
      b[n].size_ind = &i.snmpObjectValueId_size_ind;
      n++;
    }

    // value_
    //
    b[n].type = mssql::bind::string;
    b[n].buffer = &i.value_value;
    b[n].size_ind = &i.value_size_ind;
    b[n].capacity = static_cast<SQLLEN> (sizeof (i.value_value));
    n++;

    // snmpObjectFk_
    //
    b[n].type = mssql::bind::bigint;
    b[n].buffer = &i.snmpObjectFk_value;
    b[n].size_ind = &i.snmpObjectFk_size_ind;
    n++;

    // snmpObjectTypeFk_
    //
    b[n].type = mssql::bind::bigint;
    b[n].buffer = &i.snmpObjectTypeFk_value;
    b[n].size_ind = &i.snmpObjectTypeFk_size_ind;
    n++;

    // monitorHistoryFk_
    //
    b[n].type = mssql::bind::bigint;
    b[n].buffer = &i.monitorHistoryFk_value;
    b[n].size_ind = &i.monitorHistoryFk_size_ind;
    n++;
  }

  void access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  bind (mssql::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    b[n].type = mssql::bind::bigint;
    b[n].buffer = &i.id_value;
    b[n].size_ind = &i.id_size_ind;
  }

  void access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  init (image_type& i,
        const object_type& o,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    if (i.change_callback_.callback != 0)
      (i.change_callback_.callback) (i.change_callback_.context);

    // value_
    //
    {
      ::std::string const& v =
        o.value_;

      bool is_null (false);
      std::size_t size (0);
      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_image (
        i.value_value,
        sizeof (i.value_value) - 1,
        size,
        is_null,
        v);
      i.value_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }

    // snmpObjectFk_
    //
    {
      ::std::shared_ptr< ::SnmpObject > const& v =
        o.snmpObjectFk_;

      typedef object_traits< ::SnmpObject > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::SnmpObject > > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        mssql::value_traits<
            obj_traits::id_type,
            mssql::id_bigint >::set_image (
          i.snmpObjectFk_value, is_null, id);
        i.snmpObjectFk_size_ind = is_null ? SQL_NULL_DATA : 0;
      }
      else
        throw null_pointer ();
    }

    // snmpObjectTypeFk_
    //
    {
      ::std::shared_ptr< ::SnmpObjectType > const& v =
        o.snmpObjectTypeFk_;

      typedef object_traits< ::SnmpObjectType > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::SnmpObjectType > > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        mssql::value_traits<
            obj_traits::id_type,
            mssql::id_bigint >::set_image (
          i.snmpObjectTypeFk_value, is_null, id);
        i.snmpObjectTypeFk_size_ind = is_null ? SQL_NULL_DATA : 0;
      }
      else
        throw null_pointer ();
    }

    // monitorHistoryFk_
    //
    {
      ::std::shared_ptr< ::MonitorHistory > const& v =
        o.monitorHistoryFk_;

      typedef object_traits< ::MonitorHistory > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::MonitorHistory > > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        mssql::value_traits<
            obj_traits::id_type,
            mssql::id_bigint >::set_image (
          i.monitorHistoryFk_value, is_null, id);
        i.monitorHistoryFk_size_ind = is_null ? SQL_NULL_DATA : 0;
      }
      else
        throw null_pointer ();
    }
  }

  void access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // snmpObjectValueId_
    //
    {
      long unsigned int& v =
        o.snmpObjectValueId_;

      mssql::value_traits<
          long unsigned int,
          mssql::id_bigint >::set_value (
        v,
        i.snmpObjectValueId_value,
        i.snmpObjectValueId_size_ind == SQL_NULL_DATA);
    }

    // value_
    //
    {
      ::std::string& v =
        o.value_;

      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_value (
        v,
        i.value_value,
        static_cast<std::size_t> (i.value_size_ind),
        i.value_size_ind == SQL_NULL_DATA);
    }

    // snmpObjectFk_
    //
    {
      ::std::shared_ptr< ::SnmpObject >& v =
        o.snmpObjectFk_;

      typedef object_traits< ::SnmpObject > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::SnmpObject > > ptr_traits;

      if (i.snmpObjectFk_size_ind == SQL_NULL_DATA)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        mssql::value_traits<
            obj_traits::id_type,
            mssql::id_bigint >::set_value (
          id,
          i.snmpObjectFk_value,
          i.snmpObjectFk_size_ind == SQL_NULL_DATA);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<mssql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }

    // snmpObjectTypeFk_
    //
    {
      ::std::shared_ptr< ::SnmpObjectType >& v =
        o.snmpObjectTypeFk_;

      typedef object_traits< ::SnmpObjectType > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::SnmpObjectType > > ptr_traits;

      if (i.snmpObjectTypeFk_size_ind == SQL_NULL_DATA)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        mssql::value_traits<
            obj_traits::id_type,
            mssql::id_bigint >::set_value (
          id,
          i.snmpObjectTypeFk_value,
          i.snmpObjectTypeFk_size_ind == SQL_NULL_DATA);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<mssql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }

    // monitorHistoryFk_
    //
    {
      ::std::shared_ptr< ::MonitorHistory >& v =
        o.monitorHistoryFk_;

      typedef object_traits< ::MonitorHistory > obj_traits;
      typedef odb::pointer_traits< ::std::shared_ptr< ::MonitorHistory > > ptr_traits;

      if (i.monitorHistoryFk_size_ind == SQL_NULL_DATA)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        mssql::value_traits<
            obj_traits::id_type,
            mssql::id_bigint >::set_value (
          id,
          i.monitorHistoryFk_value,
          i.monitorHistoryFk_size_ind == SQL_NULL_DATA);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<mssql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }
  }

  void access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  init (id_image_type& i, const id_type& id)
  {
    {
      bool is_null (false);
      mssql::value_traits<
          long unsigned int,
          mssql::id_bigint >::set_image (
        i.id_value, is_null, id);
      i.id_size_ind = is_null ? SQL_NULL_DATA : 0;
    }
  }

  const char access::object_traits_impl< ::SnmpObjectValue, id_mssql >::persist_statement[] =
  "INSERT INTO [SnmpObjectValue] "
  "([value], "
  "[snmpObjectFk], "
  "[snmpObjectTypeFk], "
  "[monitorHistoryFk]) "
  "OUTPUT INSERTED.[snmpObjectValueId] "
  "VALUES "
  "(?, ?, ?, ?)";

  const char access::object_traits_impl< ::SnmpObjectValue, id_mssql >::find_statement[] =
  "SELECT "
  "[SnmpObjectValue].[snmpObjectValueId], "
  "[SnmpObjectValue].[value], "
  "[SnmpObjectValue].[snmpObjectFk], "
  "[SnmpObjectValue].[snmpObjectTypeFk], "
  "[SnmpObjectValue].[monitorHistoryFk] "
  "FROM [SnmpObjectValue] "
  "WHERE [SnmpObjectValue].[snmpObjectValueId]=?";

  const char access::object_traits_impl< ::SnmpObjectValue, id_mssql >::update_statement[] =
  "UPDATE [SnmpObjectValue] "
  "SET "
  "[value]=?, "
  "[snmpObjectFk]=?, "
  "[snmpObjectTypeFk]=?, "
  "[monitorHistoryFk]=? "
  "WHERE [snmpObjectValueId]=?";

  const char access::object_traits_impl< ::SnmpObjectValue, id_mssql >::erase_statement[] =
  "DELETE FROM [SnmpObjectValue] "
  "WHERE [snmpObjectValueId]=?";

  const char access::object_traits_impl< ::SnmpObjectValue, id_mssql >::query_statement[] =
  "SELECT\n"
  "[SnmpObjectValue].[snmpObjectValueId],\n"
  "[SnmpObjectValue].[value],\n"
  "[SnmpObjectValue].[snmpObjectFk],\n"
  "[SnmpObjectValue].[snmpObjectTypeFk],\n"
  "[SnmpObjectValue].[monitorHistoryFk]\n"
  "FROM [SnmpObjectValue]\n"
  "LEFT JOIN [SnmpObject] AS [snmpObjectFk] ON [snmpObjectFk].[snmpObjectId]=[SnmpObjectValue].[snmpObjectFk]\n"
  "LEFT JOIN [SnmpObjectType] AS [snmpObjectTypeFk] ON [snmpObjectTypeFk].[snmpObjectTypeId]=[SnmpObjectValue].[snmpObjectTypeFk]\n"
  "LEFT JOIN [MonitorHistory] AS [monitorHistoryFk] ON [monitorHistoryFk].[monitorHistoryId]=[SnmpObjectValue].[monitorHistoryFk]";

  const char access::object_traits_impl< ::SnmpObjectValue, id_mssql >::erase_query_statement[] =
  "DELETE FROM [SnmpObjectValue]";

  const char access::object_traits_impl< ::SnmpObjectValue, id_mssql >::table_name[] =
  "[SnmpObjectValue]";

  void access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  persist (database& db, object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mssql;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    init (im, obj, statement_insert);

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    {
      id_image_type& i (sts.id_image ());
      binding& b (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || b.version == 0)
      {
        bind (b.bind, i);
        sts.id_image_version (i.version);
        b.version++;
      }
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    obj.snmpObjectValueId_ = id (sts.id_image ());

    callback (db,
              static_cast<const object_type&> (obj),
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mssql;
    using mssql::update_statement;

    callback (db, obj, callback_event::pre_update);

    mssql::transaction& tr (mssql::transaction::current ());
    mssql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj.snmpObjectValueId_);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    init (im, obj, statement_update);

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  erase (database& db, const id_type& id)
  {
    using namespace mssql;

    ODB_POTENTIALLY_UNUSED (db);

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::SnmpObjectValue, id_mssql >::pointer_type
  access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  find (database& db, const id_type& id)
  {
    using namespace mssql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);
    auto_result ar;

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();

      ar.set (sts.find_statement ());
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      st.stream_result ();
      ar.free ();
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace mssql;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    auto_result ar (st);
    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    st.stream_result ();
    ar.free ();
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  reload (database& db, object_type& obj)
  {
    using namespace mssql;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.snmpObjectValueId_);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    auto_result ar (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    st.stream_result ();
    ar.free ();
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace mssql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r != select_statement::no_data)
    {
      ar.release ();
      return true;
    }
    else
      return false;
  }

  result< access::object_traits_impl< ::SnmpObjectValue, id_mssql >::object_type >
  access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  query (database&, const query_base_type& q)
  {
    using namespace mssql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += "\n";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        true,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) mssql::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::SnmpObjectValue, id_mssql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace mssql;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>