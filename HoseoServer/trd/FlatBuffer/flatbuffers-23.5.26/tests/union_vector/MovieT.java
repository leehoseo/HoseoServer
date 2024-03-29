﻿// automatically generated by the FlatBuffers compiler, do not modify

import com.google.flatbuffers.BaseVector;
import com.google.flatbuffers.BooleanVector;
import com.google.flatbuffers.ByteVector;
import com.google.flatbuffers.Constants;
import com.google.flatbuffers.DoubleVector;
import com.google.flatbuffers.FlatBufferBuilder;
import com.google.flatbuffers.FloatVector;
import com.google.flatbuffers.IntVector;
import com.google.flatbuffers.LongVector;
import com.google.flatbuffers.ShortVector;
import com.google.flatbuffers.StringVector;
import com.google.flatbuffers.Struct;
import com.google.flatbuffers.Table;
import com.google.flatbuffers.UnionVector;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class MovieT {
  private CharacterUnion mainCharacter;
  private CharacterUnion[] characters;

  public CharacterUnion getMainCharacter() { return mainCharacter; }

  public void setMainCharacter(CharacterUnion mainCharacter) { this.mainCharacter = mainCharacter; }

  public CharacterUnion[] getCharacters() { return characters; }

  public void setCharacters(CharacterUnion[] characters) { this.characters = characters; }


  public MovieT() {
    this.mainCharacter = null;
    this.characters = null;
  }
  public static MovieT deserializeFromBinary(byte[] fbBuffer) {
    return Movie.getRootAsMovie(ByteBuffer.wrap(fbBuffer)).unpack();
  }
  public byte[] serializeToBinary() {
    FlatBufferBuilder fbb = new FlatBufferBuilder();
    Movie.finishMovieBuffer(fbb, Movie.pack(fbb, this));
    return fbb.sizedByteArray();
  }
}

