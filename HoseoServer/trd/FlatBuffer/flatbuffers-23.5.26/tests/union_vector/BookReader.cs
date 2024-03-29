﻿// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

using global::System;
using global::System.Collections.Generic;
using global::Google.FlatBuffers;

public struct BookReader : IFlatbufferObject
{
  private Struct __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public void __init(int _i, ByteBuffer _bb) { __p = new Struct(_i, _bb); }
  public BookReader __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public int BooksRead { get { return __p.bb.GetInt(__p.bb_pos + 0); } }
  public void MutateBooksRead(int books_read) { __p.bb.PutInt(__p.bb_pos + 0, books_read); }

  public static Offset<BookReader> CreateBookReader(FlatBufferBuilder builder, int BooksRead) {
    builder.Prep(4, 4);
    builder.PutInt(BooksRead);
    return new Offset<BookReader>(builder.Offset);
  }
  public BookReaderT UnPack() {
    var _o = new BookReaderT();
    this.UnPackTo(_o);
    return _o;
  }
  public void UnPackTo(BookReaderT _o) {
    _o.BooksRead = this.BooksRead;
  }
  public static Offset<BookReader> Pack(FlatBufferBuilder builder, BookReaderT _o) {
    if (_o == null) return default(Offset<BookReader>);
    return CreateBookReader(
      builder,
      _o.BooksRead);
  }
}

public class BookReaderT
{
  [Newtonsoft.Json.JsonProperty("books_read")]
  public int BooksRead { get; set; }

  public BookReaderT() {
    this.BooksRead = 0;
  }
}

